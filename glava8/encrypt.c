// encrypt.c
#include "encrypt.h"

void encrypt(char *message) {
    char key = 13; // Ключ для XOR (можно любой, подходит для примера)
    while (*message) {
        *message = *message ^ key;
        message++;
    }
}