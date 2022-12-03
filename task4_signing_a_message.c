/**
 * RSA-signs the given secret message.
 */
#include "rsa.h"

int main() {

    // Initialize the secret message "Plate: YYXR 481 -> Illegal Turn"
    BIGNUM *secretMsg = BN_new();
    BN_hex2bn(&secretMsg, "506C6174653A205959585220343831202D3E20496C6C6567616C205475726E");

    // Initialize the modulus and keys
    BIGNUM *modulus = BN_new();
    BIGNUM *privateKey = BN_new();
    BIGNUM *publicKey = BN_new();
    BN_hex2bn(&modulus, "34A8D");
    BN_hex2bn(&privateKey, "0251F9BE6FFE4C385794BED039864BBC1B1F3324A542D9597F8AF00C7306A5F5");
    BN_hex2bn(&publicKey, "3A01FB9D00D64A8299D89E01EB02B2D3F88992C804ECDC1058EFB475CEA4EE3");

    // Encrypt the secret message with the private key and print the RSA signature
    BIGNUM *encryption = getRSAEncryption(secretMsg, privateKey, publicKey);
    printBN("The signature for Task 4(a) is:", encryption);
    printf("The verification decryption of the encryption (i.e., secret message) for Task 4(a) is: ");
    printHex(BN_bn2hex(getRSADecryption(encryption, modulus, publicKey)));

    // Assign a different message "Plate: YYXR 482 -> Illegal Turn"
    BN_hex2bn(&secretMsg, "506C6174653A205959585220343832202D3E20496C6C6567616C205475726E");
    
    // Encrypt the different message with the private key and print the signature
    encryption = getRSAEncryption(secretMsg, privateKey, publicKey);
    printBN("The signature for Task 4(b) is:", encryption);
    printf("The verification decryption of the encryption (i.e., secret message) for Task 4(b) is: ");
    printHex(BN_bn2hex(getRSADecryption(encryption, modulus, publicKey)));
}