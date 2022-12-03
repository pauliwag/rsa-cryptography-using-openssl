/**
 * Derives the RSA private key for the given public key (e, n) utilizing the
 * modulo inverse of the totatives of n, where e is a given prime
 * modulus and n is the product of given large primes p and q.
 */
#include "rsa.h"

int main() {
    
    // Initialize the large primes
    BIGNUM *p = BN_new();
    BIGNUM *q = BN_new();
    BN_hex2bn(&p, "D40C38D7074F8557BF520C0AA31D6DC3");
    BN_hex2bn(&q, "5AF21620C416E47AFF4C3AEF880C772B");
        
    // Initialize the prime modulus
    BIGNUM *e = BN_new();
    BN_hex2bn(&e, "1C901");

    // Get the RSA private key and print it
    BIGNUM *privateKey = getRSAPrivateKey(p, q, e);
    printBN("The private key, d, is:", privateKey);
}