#include <openssl/des.h>
#include <openssl/conf.h>
#include <openssl/evp.h>
#include <openssl/err.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ENC 1
#define DEC 0

int verify_args(int argc)
{
	return argc != 5;
}

unsigned long convert_to_hex(const char* string)
{
	unsigned long number = (unsigned long)(strtoul(string, NULL, 16));
	return number;
}

// i may need this later so i'll keep it for now
void flip_endian(unsigned char* string)
{
	unsigned char new_string[8];
	memcpy(string, new_string, 8);
	int i=0;
	int upper_limit = 7;
	for(i=0; i<8; i++)
	{
		string[i] = new_string[upper_limit - i];	
	}
}	

int main(int argc, char **argv)
{
	if(verify_args(argc))
	{
		printf("Usage\n\t./des iv key in-file out-file\n");
	}

	int k;
	unsigned int in[2];
	static unsigned char cbc_key[8];
	unsigned long hex = convert_to_hex(argv[2]);
	memcpy(cbc_key, &hex, 8);

	unsigned long iv = convert_to_hex(argv[1]);
	des_key_schedule key;

	if ((k = des_set_key_checked(&cbc_key,key)) != 0)
	{
		printf("\nkey error\n");
		exit(1);
	}

	in[0] = 0x0;
	in[1] = 0x0;
	
	FILE *plaintext = fopen("input.txt", "r");
	unsigned char buffer[9];
	unsigned long long_buffer = 0;
	size_t num_of_items = 0;
	
	// get size of file
	
	// scroll through all of file by going in intervals
	// of 8 until it is lower than that
	fseek(plaintext, 0L, SEEK_END);
	int file_size = ftell(plaintext);	
	fseek(plaintext, 0L, SEEK_SET);

	while(file_size)
	{
		int bytes_to_read = 8;
		if(file_size < 8)
		{
			bytes_to_read = file_size;
		}

		// makeing sure no trash data is in memory
		long_buffer = 0;
		memset(buffer, 0, 8);

		// reading the data into buffer
		fread(&long_buffer, bytes_to_read, 1, plaintext);

		// encrypting or decrypting

		// writing to file
		memcpy(buffer, &long_buffer, sizeof(unsigned long));
		printf("Bufstart:%s:Bufend\n", buffer); 

		file_size -= bytes_to_read;
	}

	fclose(plaintext);

	printf("\n");
	printf("DES Clear Text: \n\t%ld\n\t%ld\n", in[0], in[1]);

	des_encrypt1((unsigned int*)in,key,ENC);
	printf("DES Encryption: \n\t%ld\n\t%ld\n",in[0],in[1]);

	des_encrypt1((unsigned int*)in,key,DEC);
	printf("DES Decryption: \n\t%ld\n\t%ld\n", in[0], in[1]);
}
