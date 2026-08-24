#include "../include/whoami.h"
#include <stdio.h>
#include <stdlib.h>

void whoami(void) {
    char *user = getenv("USER");
    if (!user) {
        printf("nothing\n");
    } else {
        printf("current user: %s\n", user);
    }
}
