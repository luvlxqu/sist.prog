// bank_vault.c
#include <stdio.h>
#include <encrypt.h>
#include <checksum.h>

int main() {
    char password[] = "Сейф#1234";
    printf("Исходный пароль: %s\n", password);
    printf("Контрольная сумма: %i\n", checksum(password));

    encrypt(password);
    printf("Зашифрованный пароль: %s\n", password);
    printf("Контрольная сумма: %i\n", checksum(password));

    encrypt(password);
    printf("Расшифрованный пароль: %s\n", password);
    printf("Контрольная сумма: %i\n", checksum(password));

    return 0;
}