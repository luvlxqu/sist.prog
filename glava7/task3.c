#include <stdio.h>

// Определение типов ответов
typedef enum {
    DUMP,
    SECOND_CHANCE,
    MARRIAGE
} response_type;

// Структура ответа
typedef struct {
    char *name;
    response_type type;
} response;

// Функции-действия
void dump(response r) {
    printf("%s: Расстаться (DUMP)\n", r.name);
}

void second_chance(response r) {
    printf("%s: Дать второй шанс (SECOND_CHANCE)\n", r.name);
}

void marriage(response r) {
    printf("%s: Пожениться (MARRIAGE)\n", r.name);
}

int main()
{
    response r[] = {
        {"Майк", DUMP}, 
        {"Луис", SECOND_CHANCE},
        {"Мэттью", SECOND_CHANCE}, 
        {"Уильям", MARRIAGE}
    };
    
    int i;
    for (i = 0; i < 4; i++) {
        switch(r[i].type) {
            case DUMP:
                dump(r[i]);
                break;
            case SECOND_CHANCE:
                second_chance(r[i]);
                break;
            default:
                marriage(r[i]);
        }
    }
    return 0;
}