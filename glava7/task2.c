#include <stdio.h>
#include <string.h>

#define NUM_ADS 7

char *ADS[] = {
    "Виктор: любит спорт, не курит, любит театр, не любит Бибера",
    "Мария: курит, любит живопись, любит театр, любит перекусить",
    "Иван: некурящий, любит тренировки в зале, не любит живопись",
    "Ольга: любит Бибера, любит спорт, курит",
    "Петр: некурящий, любит театр, любит живопись",
    "Анна: любит перекусить, не любит спорт, не курит",
    "Сергей: любит спорт, не любит театр, не курит, не любит Бибера"
};

int sports_no_bieber(char *s)  
{  
    return strstr(s, "спорт") && !strstr(s, "Бибер");  
}  

int sports_or_workout(char *s)  
{  
    return strstr(s, "спорт") || strstr(s, "тренировки в зале");  
}  

int ns_theater(char *s)  
{  
    return strstr(s, "некурящий") && strstr(s, "театр");  
}  

int arts_theater_or_dining(char *s)  
{  
    return strstr(s, "живопись") || strstr(s, "театр") || strstr(s, "перекусить");  
}  

void find(int (*match)(char *))  
{  
    int i;  
    puts("Search results:");  
    puts("---");  
    for (i = 0; i < NUM_ADS; i++) {  
        if (match(ADS[i])) {  
            printf("%s\n", ADS[i]);  
        }  
    }  
    puts("---");  
}  

int main() {
    printf("1. Тот, кто любит спорт и не любит Бибера:\n");
    find(sports_no_bieber);

    printf("\n2. Тот, кто любит спорт или тренировки в зале:\n");
    find(sports_or_workout);

    printf("\n3. Тот, кто не курит и любит театр:\n");
    find(ns_theater);

    printf("\n4. Тот, кто любит живопись, театр или перекусить:\n");
    find(arts_theater_or_dining);

    return 0;
}