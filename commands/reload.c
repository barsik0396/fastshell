#include "../include/reload.h"
#include <stdio.h>
#include <unistd.h>

void reload(char *current) {
    printf("checking fastshell...\n");
    if (access(current, F_OK) == 0) {
        printf("found fastshell: %s\n", current);
        execl(current, NULL);
    } else {
        printf("fastshell not found!\n");
    }
}