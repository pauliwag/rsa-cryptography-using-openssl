#ifndef __RSA_H__
#define __RSA_H__

#include <openssl/bn.h>
#include "utils.h"

BIGNUM *getRSAPrivateKey(BIGNUM *p, BIGNUM *q, BIGNUM *e);
BIGNUM *getRSAEncryption(BIGNUM *secretMsg, BIGNUM *modulus, BIGNUM *publicKey);
BIGNUM *getRSADecryption(BIGNUM *encryption, BIGNUM *privateKey, BIGNUM *publicKey);

#endif