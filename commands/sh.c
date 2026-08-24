#include "../include/sh.h"
#include "../input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sh(void) {
    printf("Welcome to sh! Type 'exit' to return to fastshell.\n");
    while (1) {
        char buffer[8192]; // very big but not unlimited
        printf("sh@fastshell-01$ ");
        char *output = input(buffer);
        if (strcmp(output, "exit") == 0) {
            printf("Bye!\n");
            break;
        }
        system(output); // known problems: GCC shows "ignoring return value of ‘system’" warning
    }
}
