# RSA Cryptography Using OpenSSL

These are my solutions to Dr. Du's SEED lab *RSA Public-Key Encryption and Signature*, leveraging the OpenSSL library for the purpose of obtaining experimental results for recommending cryptographic mechanisms to be employed in roadside computer system units that automatically detect a variety of traffic violations and transmit sensitive information to a central database.  

You can compile a module using the `crypto` library like so:

```
$ gcc task5_verifying_a_signature.c rsa.c utils.c -lcrypto
```