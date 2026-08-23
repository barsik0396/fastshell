#include "call.h"
#include "input.h"
#include <stdio.h>

#ifdef _WIN32
#error "do not compile fastshell on windows!"
#endif

int main(void) {
    while (1) {
        char buffer[8192];
        printf("fastshell# ");
        char *output = input(buffer);
        call(output);
    }
}
