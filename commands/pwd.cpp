#include "../etc/dirs.h"
#include "../include/pwd.h"
#include <iostream>

using namespace std; // `std::cout` -> `cout`

void pwd(void) {
    cout << get_dir_now() << "\n";
}