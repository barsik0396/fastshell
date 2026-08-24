#include "expanduser.h"
#include <stdlib.h>
#include <string.h>
#include <pwd.h>
#include <unistd.h>

char *expanduser(char *path) {
    char *home = NULL;
    char *rest = NULL;
    if (path[1] == '\0' || path[1] == '/') {
        home = getenv("HOME");
        if (!home) {
            struct passwd *pw = getpwuid(getuid());
            if (!pw) {
                return NULL;
            }
            home = pw->pw_dir;
        }
        rest = path + 1;
    }
    size_t home_len = strlen(home);
    size_t rest_len = strlen(rest);
    char *result = malloc(home_len + rest_len + 1);
    if (!result) {
        return NULL;
    }
    memcpy(result, home, home_len);
    memcpy(result + home_len, rest, rest_len + 1);
    return result;
}