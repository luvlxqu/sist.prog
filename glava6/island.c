#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct island {
    char *name;
    char *opens;
    char *closes;
    struct island *next;
} island;

island* create(char *name)
{
    island *i = malloc(sizeof(island));
    i->name = strdup(name);
    i->opens = "09:00";
    i->closes = "17:00";
    i->next = NULL;
    return i;
}

void display(island *start)
{
    island *i = start;
    for (; i != NULL; i = i->next) {
        printf("Название: %s открыт: %s-%s\n", i->name, i->opens, i->closes);
    }
}

void release(island *start)
{
    island *i = start;
    island *next = NULL;
    for (; i != NULL; i = next) {
        next = i->next;
        free(i->name);
        free(i);
    }
}

int main()
{
    char name[80];

    printf("Введите название первого острова: ");
    fgets(name, 80, stdin);
    name[strcspn(name, "\n")] = '\0';
    island *p_island0 = create(name);

    printf("Введите название второго острова: ");
    fgets(name, 80, stdin);
    name[strcspn(name, "\n")] = '\0';
    island *p_island1 = create(name);

    p_island0->next = p_island1;

    printf("\nСписок островов:\n");
    display(p_island0);

    release(p_island0);

    return 0;
}