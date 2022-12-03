/**
 * RSA-decrypts the given encryption.
 */
#include "rsa.h"

int main() {

    // Initialize the encryption
    BIGNUM *encryption = BN_new();
    BN_hex2bn(&encryption, "ED3C75C55905421A53FDB335D0E48FE0C38DECC6F2B0E2403F217586867ED0");

    // Initialize the private and public keys
    BIGNUM *privateKey = BN_new();
    BIGNUM *publicKey = BN_new();
    BN_hex2bn(&privateKey, "0251F9BE6FFE4C385794BED039864BBC1B1F3324A542D9597F8AF00C7306A5F5");
    BN_hex2bn(&publicKey, "3A01FB9D00D64A8299D89E01EB02B2D3F88992C804ECDC1058EFB475CEA4EE3");

    // Get the RSA decryption of the encryption and print it
    BIGNUM *decryption = getRSADecryption(encryption, privateKey, publicKey);
    printf("The decryption of the encryption for Task 3 is: ");
    printHex(BN_bn2hex(decryption));
}