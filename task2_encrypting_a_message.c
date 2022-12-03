/**
 * RSA-encrypts the given secret message.
 */
#include "rsa.h"

int main() {

    // Initialize the secret message "Plate: LSRE 845 -> Failed Stop" in hex
    BIGNUM *secretMsg = BN_new();
    BN_hex2bn(&secretMsg, "506C6174653A204C53524520383435202D3E204661696C65642053746F70");

    // Initialize the modulus and public key
    BIGNUM *modulus = BN_new();
    BIGNUM *publicKey = BN_new();
    BN_hex2bn(&modulus, "34A8D");
    BN_hex2bn(&publicKey, "3A01FB9D00D64A8299D89E01EB02B2D3F88992C804ECDC1058EFB475CEA4EE3");

    // Get the RSA encryption of the secret message and print it
    BIGNUM *encryption = getRSAEncryption(secretMsg, modulus, publicKey);
    printBN("The RSA encryption of the secret message is:", encryption);

    // Verify the encryption by utilizing the given private key to decrypt back to the secret message
    BIGNUM *privateKey = BN_new();
    BN_hex2bn(&privateKey, "0251F9BE6FFE4C385794BED039864BBC1B1F3324A542D9597F8AF00C7306A5F5");
    BIGNUM *decryption = getRSADecryption(encryption, privateKey, publicKey);

    // Print the verification results
    printf("The verification decryption of the encryption for Task 2 is: ");
    printHex(BN_bn2hex(decryption));
}