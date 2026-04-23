#include <stdio.h>
#include <stdarg.h>

// Список напитков
enum drink {
    MONKEY_GLAND,
    MUDSLIDE,
    FUZZY_NAVEL,
    SEX_ON_THE_BEACH,
    BLOODY_MARY
};

// Функция возвращает цену напитка
double price(enum drink d) {
    switch(d) {
        case MONKEY_GLAND:
            return 4.5;
        case MUDSLIDE:
            return 5.2;
        case FUZZY_NAVEL:
            return 7.2;
        case SEX_ON_THE_BEACH:
            return 6.8;
        case BLOODY_MARY:
            return 5.5;
        default:
            return 0;
    }
}

// Функция подсчёта общей стоимости (как в вашем файле)
double total(int args, ...)
{
    double total = 0;
    va_list ap;
    va_start(ap, args);
    
    int i;
    for(i = 0; i < args; i++)
    {
        enum drink d = va_arg(ap, enum drink);
        total = total + price(d);
    }
    
    va_end(ap);
    return total;
}

int main()
{
    // Проверяем работу
    printf("Цена равняется %.2f\n", total(3, MONKEY_GLAND, MUDSLIDE, FUZZY_NAVEL));
    // Результат: Цена равняется 16.90 (4.5 + 5.2 + 7.2 = 16.9)
    
    // Можно посчитать другие комбинации
    printf("Цена равняется %.2f\n", total(2, SEX_ON_THE_BEACH, BLOODY_MARY));
    
    return 0;
}