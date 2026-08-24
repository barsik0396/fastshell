#include "../include/whoami.h"
#include <stdio.h>
#include <stdlib.h>

void whoami(void) {
    char *user = getenv("USER");
    if (!user) {
        printf("nothing");
    } else {
        printf("current user: %s", user);
    }
}
