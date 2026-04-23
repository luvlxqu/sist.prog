#include <stdio.h>

// Определяем типы ответов
typedef enum {
    DUMP,
    SECOND_CHANCE,
    MARRIAGE
} response_type;

// Структура для ответа
typedef struct {
    char *name;
    response_type type;
} response;

// Функции для разных типов ответов
void dump(response r) {
    printf("%s: Расстаться\n", r.name);
}

void second_chance(response r) {
    printf("%s: Дать второй шанс\n", r.name);
}

void marriage(response r) {
    printf("%s: Пожениться\n", r.name);
}

// Массив указателей на функции (как в вашем файле)
void (*replies[]) (response) = {dump, second_chance, marriage};

int main()
{
    response r[] = {
        {"Майк", DUMP}, {"Луис", SECOND_CHANCE},
        {"Мэттью", SECOND_CHANCE}, {"Уильям", MARRIAGE}
    };

    int i;
    for (i = 0; i < 4; i++) {
        (replies[r[i].type])(r[i]);  // Вызываем нужную функцию через указатель
    }
    return 0;
}