
In this folder you will find the following files:

- tempdes.c : is a sample code for encrypting / decrypting using DES
- tempsha1.c : is a sample code for digest generation using SHA1
- test.txt,test2.txt,test3.txt: are sample plain text files to test your code
- test.des,test2.des,test3.des: are DES encrypted versions of files test.txt,test2.txt,test3.txt. 
  Key and IV values used are as follows.
	- Key = 40fedf386da13d57 (Hexadecimal values)
	- IV  = fedcba9876543210 (Hexadecimal values)
- func_desc.txt: Brief description of built in functions you are allowed to
  use.

- EVPSymmetricEnc.c, a modern Openssl implementation of EVP Symmetric Encryption and Decryption
from: https://wiki.openssl.org/index.php/EVP_Symmetric_Encryption_and_Decryption
The EVP library provides a high-level interface to cryptographic functions. 

- SymmetricEnc.java, this is a sample implementation for Java you need to convert.

All the c code can be compiled and executed using the following commands:

- In the linux command line, execute "gcc -o tempdes tempdes.c -lcrypto", where tempdes.c 
is the source code and tempdes is the name of the executable that sill be generated This 
command will compile your code and generate an executable.

- To execute the program you just created (tempdes in our example), in the linux command 
line write "./tempdes"

If you are getting errors, make sure that you have installed the openssl libraries:

apt-get install libssl1.0-dev libssl-dev

For Java use the SymmetricEnc.java file.

For python, you can use an openssl wrapper from here: 

- https://www.dlitz.net/software/pycrypto/api/2.6/

or

- https://cryptography.io/en/latest/installation/
