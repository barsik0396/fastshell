#include "input.h"
#include <string.h>
#include <stdio.h>

char *input(char *buffer) {
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    return buffer;
}
