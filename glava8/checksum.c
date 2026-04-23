// checksum.c
#include "checksum.h"

int checksum(const char *message) {
    int sum = 0;
    while (*message) {
        sum += *message;
        message++;
    }
    return sum;
}