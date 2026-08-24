#include "panic.h"
#include "isdbg.h"
#include <iostream>
#include "panic.h"

extern "C" {
    void panic(char *file, int line, char *title, char *text) {
        std::cout <<
            " \x1b[31;1m!!! PANIC !!!\x1b[0m\n" // 31 - red, 1 - bold, 0 - reset
            << "File: "
            << file
            << "\nLine: "
            << line
            << "\n\n"
            << "File: "
            << __FILE__
            << "Line: "
            << __LINE__-11
            << " (r: "
            << __LINE__
            << ")\n\n"
            << "ERROR: "
            << "\x1b[1;37m" // 1 - bold, 37 - white
            << title
            << "\x1b[0m: " // 0 - reset
            << text
            << "\n"
            << std::flush
            ;
        if (isdbg()) {
            asm("int3"); // breakpoint
            abort(); // SIGABRT
        } else {
            exit(1);
        }
    }
}
