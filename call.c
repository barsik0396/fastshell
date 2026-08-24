#include "call.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "include/sh.h"
#include "include/cycle.h"
#include "include/help.h"
#include "include/whoami.h"
#include "include/reload.h"

void call(char *text, char *argv_1) {
    if (strcmp(text, "exit") == 0) {
        exit(0);
    } else if (strcmp(text, "sh") == 0) {
        sh();
    } else if (strcmp(text, "cycle") == 0) {
        cycle();
    } else if (strcmp(text, "help") == 0) {
        help();
    } else if (strcmp(text, "whoami") == 0) {
        whoami();
    } else if (strcmp(text, "reload") == 0) {
        reload(argv_1);
    } else if (strlen(text) == 0) {
        // nothing
    } else {
        printf("\x1b[1;31mUnknown command!\x1b[0m\n");
    }
}
