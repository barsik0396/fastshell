#include "call.h"
#include "input.h"
#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#error "do not compile fastshell on windows!"
#endif

int main(void) {
    char *user = getenv("USER");
    if (!user) {
        printf("\x1b[1;37mfastshell\x1b[0m \x1b[33;1mwarn\x1b[0m no USER var found in env!\n");
    }
    while (1) {
        char buffer[8192];
        if (user) {
            printf("(%s) fastshell# ", user);
        } else {
            printf("fastshell# ");
        }
        char *output = input(buffer);
        call(output);
    }
}
