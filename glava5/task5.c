#include <stdio.h>


typedef union {
    float lemon;       
    int lime_pieces;   
} lemon_lime;

// Структура для рецепта Маргариты
typedef struct {
    float tequila;   
    float cointreau;   
    lemon_lime citrus; 
} margarita;

int main() {
    margarita margarita_lemon = {2.0, 1.0, {.lemon=0.5}};

    // Создаем рецепт с лаймом
    margarita margarita_lime = {2.0, 1.0, {.lime_pieces=2}};

    printf("Рецепт Маргариты с лимоном:\n");
    printf("Текила: %.2f порций\n", margarita_lemon.tequila);
    printf("Куантро: %.2f порций\n", margarita_lemon.cointreau);
    printf("Цитрус: %.2f мл лимонного сока\n", margarita_lemon.citrus.lemon);

    printf("\nРецепт Маргариты с лаймом:\n");
    printf("Текила: %.2f порций\n", margarita_lime.tequila);
    printf("Куантро: %.2f порций\n", margarita_lime.cointreau);
    printf("Цитрус: %d кусочка лайма\n", margarita_lime.citrus.lime_pieces);
    return 0;
}