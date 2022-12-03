#ifndef __UTILS_H__
#define __UTILS_H__

#include <openssl/bn.h>
#include <stdio.h>
#include <string.h>

void printBN(char *msg, BIGNUM *a);
void printHex(const char *a);
int hex2ASCII(const char a, const char b);
int hex2Int(char a);

#endif