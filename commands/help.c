#include "../include/help.h"
#include <stdio.h>

void help(void) {
    printf("fastshell v0.2.0 - commands:\n");
    printf("  help               show this help\n");
    printf("  cycle              just \"for (i <= 1000000)\"...\n");
    printf("  sh                 run non-fastshell commands\n");
    printf("  reload             restart fastshell");
    printf("  whoami             who am i?");
}
