#include "../include/sh.h"
#include <iostream>

extern "C" {
    void cycle(void) {
        std::cout << "Start!\n";
        for (int i = 0; i <= 1000000; i++) {
            std::cout <<
                "\rPassed: "
                << i
                << "; Left: "
                << 1000000-i
            ;
        }
        std::cout << "\nDONE\n";
    }
}