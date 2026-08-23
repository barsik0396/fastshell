#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool isdbg(void) {
#ifdef __linux__ // because func is linux-only
    char buf[4096];
    bool detected = false;

    FILE *fp = fopen("/proc/self/status", "r");
    if (!fp) {
        return false;
    }

    while (fgets(buf, sizeof(buf), fp) != NULL) {
        const char *prefix = "TracerPid:";
        if (strncmp(buf, prefix, strlen(prefix)) == 0) {
            int tracer_pid = atoi(buf + strlen(prefix));
            detected = (tracer_pid != 0);
            break;
        }
    }

    fclose(fp);
    return detected;
#else
    return false
#endif
}
