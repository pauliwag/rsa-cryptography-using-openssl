/**
 * Verifies an RSA signature.
 */
#include "rsa.h"

int main() {

    // Initialize the message "Plate: AUHW 090 -> Clear Record", signature, modulus, and public key
    BIGNUM *secretMsg = BN_new();
    BIGNUM *signature = BN_new();
    BIGNUM *modulus = BN_new();
    BIGNUM *publicKey = BN_new();
    BN_hex2bn(&secretMsg, "506C6174653A204155485720303930202D3E20436C656172205265636F7264");
    BN_hex2bn(&signature, "03AC5204A8B69CE6B565C818C47F6263BC1C2290F400AF199BB097BCAECCFCBE");
    BN_hex2bn(&modulus, "88D35");
    BN_hex2bn(&publicKey, "605A933FFBFEAEB8E290D31D9894B9646FF967D21A9D420680F8FA390855097");

    // Decrypt the given RSA signature with the public key, and compare to the given message
    BIGNUM *decryption = getRSADecryption(signature, modulus, publicKey);
    printf("The decrypted signature for Task 5(a) is: ");
    printHex(BN_bn2hex(decryption));
    printf("Comparing to the given message: ");
    printHex(BN_bn2hex(secretMsg));

    // Corrupt the signature (change last byte to BF) and try verifying again
    BN_hex2bn(&signature, "03AC5204A8B69CE6B565C818C47F6263BC1C2290F400AF199BB097BCAECCFCBF");
    decryption = getRSADecryption(signature, modulus, publicKey);
    printf("The decrypted corrupted signature for Task 5(b) is: ");
    printHex(BN_bn2hex(decryption));
}