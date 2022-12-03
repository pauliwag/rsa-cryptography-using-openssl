#include "utils.h"

/**
 * Prints the given message followed by the given BIGNUM in hex,
 * separated by a single space.
 */
void printBN(char *msg, BIGNUM *a) {
    char *numberStr = BN_bn2hex(a);
    printf("%s %s\n", msg, numberStr);
    OPENSSL_free(numberStr);
}

/**
 * Converts the given hex to ASCII and prints it;
 * leverages auxiliary hex2ASCII().
 */
void printHex(const char *a) {
    int len = strlen(a);
    if (len % 2 != 0) {
        printf("%s\n", "Invalid hex length");
        return;
    }
    char buf = 0;
    int i;
    for (i = 0; i < len; ++i) {
        if (i % 2 != 0) {
            printf("%c", hex2ASCII(buf, a[i]));
        } else {
            buf = a[i];
        }
    }
    printf("\n");
}

int hex2ASCII(const char a, const char b) {
    int hi = hex2Int(a) * 16;
    int lo = hex2Int(b);
    return hi + lo;
}

int hex2Int(char a) {
    if (a >= 97) {
        a -= 32;
    }
    int first = a / 16 - 3;
    int second = a % 16;
    int res = first * 10 + second;
    if (res > 9) {
        --res;
    }
    return res;
}