// treadmill.c
#include <stdio.h>
#include <hfcal.h>   // Заголовок в /usr/local/include, угловые скобки работают

int main() {
    double distance_miles = 5.0;
    double weight_lbs = 150.0;

    double distance_km = miles_to_km(distance_miles);
    double weight_kg = lbs_to_kg(weight_lbs);

    printf("=== Беговая дорожка (UK версия) ===\n");
    printf("Дистанция: %.2f миль = %.2f км\n", distance_miles, distance_km);
    printf("Вес пользователя: %.2f фунтов = %.2f кг\n", weight_lbs, weight_kg);

    return 0;
}