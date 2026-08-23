#include "call.h"
#include "input.h"
#include <stdio.h>

int main(void) {
    while (1) {
        char buffer[8192];
        printf("fastshell# ");
        char *output = input(buffer);
        call(output);
    }
}
