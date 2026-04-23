#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    char *feeds[] = {
        "http://www.cnn.com/rss/celeb.xml",
        "http://www.rollingstone.com/rock.xml",
        "http://eonline.com/gossip.xml"
    };
    
    int times = 3;
    
    if (argc < 2) {
        fprintf(stderr, "Использование: %s <поисковый запрос>\n", argv[0]);
        return 1;
    }
    
    char *phrase = argv[1];
    int i;
    
    for (i = 0; i < times; i++) {
        char var[255];
        sprintf(var, "RSS_FEED=%s", feeds[i]);
        char *vars[] = {var, NULL};
        pid_t pid = fork();
        
        if (pid == -1) {
            fprintf(stderr, "Не могу клонировать процесс: %s\n", strerror(errno));
            return 1;
        }
        
        if (pid == 0) {

            if (execle("/usr/bin/python3", "/usr/bin/python3", "./rssgossip.py", phrase, NULL, vars) == -1) {
                fprintf(stderr, "Не могу запустить скрипт: %s\n", strerror(errno));
                return 1;
            }
        }
    }
    
    for (i = 0; i < times; i++) {
        int status;
        wait(&status);
    }
    
    return 0;
}