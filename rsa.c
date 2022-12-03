/**
 * @author Paul Roode
 */
#include "rsa.h"

/**
 * Gets the RSA private key for a given public key (e, n) utilizing the
 * modulo inverse of the totatives of n, where e is a given prime
 * modulus and n is the product of given large primes p and q.
 */
BIGNUM *getRSAPrivateKey(BIGNUM *p, BIGNUM *q, BIGNUM *e) {
    BN_CTX *ctx = BN_CTX_new();
    BIGNUM *one = BN_new();
    BIGNUM *pLessOne = BN_new();
    BIGNUM *qLessOne = BN_new();
    BIGNUM *totient = BN_new();

    BN_dec2bn(&one, "1");
    BN_sub(pLessOne, p, one);
    BN_sub(qLessOne, q, one);
    BN_mul(totient, pLessOne, qLessOne, ctx);

    BIGNUM *privateKey = BN_new();
    BN_mod_inverse(privateKey, e, totient, ctx);
    BN_CTX_free(ctx);
    return privateKey;
}

/**
 * Gets the RSA encryption of the given secret message utilizing the
 * given prime modulus and public key.
 */
BIGNUM *getRSAEncryption(BIGNUM *secretMsg, BIGNUM *modulus, BIGNUM *publicKey) {
    BN_CTX *ctx = BN_CTX_new();
    BIGNUM *encryption = BN_new();

    /* Compute the RSA encryption as "secretMsg ^ modulus % publicKey".
     * Note: BN_mod_exp() uses less time and space than BN_exp(). */
    BN_mod_exp(encryption, secretMsg, modulus, publicKey, ctx);
    
    BN_CTX_free(ctx);
    return encryption;
}

/**
 * Gets the RSA decryption of the given encryption utilizing the
 * given private and public keys.
 */
BIGNUM *getRSADecryption(BIGNUM *encryption, BIGNUM *privateKey, BIGNUM *publicKey) {
    BN_CTX *ctx = BN_CTX_new();
    BIGNUM *decryption = BN_new();

    /* Compute the RSA decryption as "encryption ^ privateKey % publicKey".
     * Note: BN_mod_exp() uses less time and space than BN_exp(). */
    BN_mod_exp(decryption, encryption, privateKey, publicKey, ctx);

    BN_CTX_free(ctx);
    return decryption;
}