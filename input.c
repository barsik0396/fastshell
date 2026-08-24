#include "input.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char *input(char *buffer) {
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) { // if EOF
        printf("\nBye!\n");
        exit(0);
    }
    buffer[strcspn(buffer, "\n")] = '\0';
    return buffer;
}
