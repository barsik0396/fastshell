#include "expanduser.h"
#include <stdlib.h>
#include <string.h>
#include <pwd.h>
#include <unistd.h>

char *expanduser(const char *path) {
    if (!path) {
        return NULL;
    }
    if (path[0] != '~') {
        return strdup(path);
    }
    if (!(path[1] == '\0' || path[1] == '/')) {
        return strdup(path);
    }
    const char *rest = path + 1;
    char *home = getenv("HOME");
    if (!home) {
        struct passwd *pw = getpwuid(getuid());
        if (!pw || !pw->pw_dir) {
            return NULL;
        }
        home = pw->pw_dir;
    }
    size_t home_len = strlen(home);
    size_t rest_len = strlen(rest);
    size_t total = home_len + rest_len + 1;
    char *result = malloc(total);
    if (!result) {
        return NULL;
    }
    size_t idx = 0;
    for (size_t i = 0; i < home_len; ++i) result[idx++] = home[i];
    for (size_t i = 0; i < rest_len; ++i) result[idx++] = rest[i];
    result[idx] = '\0';
    return result;
}
