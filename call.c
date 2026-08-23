#include "call.h"
#include <string.h>
#include <stdlib.h>

#include "include/sh.h"
#include "include/cycle.h"
#include "include/help.h"

void call(char *text) {
    if (strcmp(text, "exit") == 0) {
        exit(0);
    } else if (strcmp(text, "sh") == 0) {
        sh();
    } else if (strcmp(text, "cycle") == 0) {
        cycle();
    } else if (strcmp(text, "help") == 0) {
        help();
    }
}