#include "../include/sh.h"
#include "../input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sh(void) {
    printf("Welcome to sh! Type 'exit' to return to fastshell.\n");
    while (1) {
        char buffer[8192];
        printf("sh@fastshell-01$ ");
        char *output = input(buffer);
        if (strcmp(output, "exit") == 0) {
            printf("Bye!\n");
            break;
        }
        system(output);
    }
}
