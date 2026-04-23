#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* now() {
    time_t t;
    time(&t);
    return asctime(localtime(&t));
}

int main() {
    char comment[80];
    char cmd[120];

    printf("Введите комментарий: ");
    fgets(comment, 80, stdin);

    int len = strlen(comment);
    if (len > 0 && comment[len-1] == '\n') {
        comment[len-1] = '\0';
    }

    sprintf(cmd, "echo '%s %s' >> reports.log", comment, now());

    system(cmd);
    
    printf("Запись добавлена в reports.log\n");
    
    return 0;
}