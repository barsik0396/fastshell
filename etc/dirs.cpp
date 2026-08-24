#include "dirs.h"
#include <iostream>
#include <filesystem>

// "pwd"
extern "C" char *get_dir_now(void) {
    static std::string data = std::filesystem::current_path(); // gets current directory

    return data.data();
}

// "cd"
extern "C" void change_dir(char *dir) {
    try {  // yes, it exists in C++!
        std::filesystem::current_path(dir); // changes directory
    } catch (const
        std::filesystem::filesystem_error& e // every filesystem error
    ) {
        std::cerr << "Error: "
        << e.what()               // returns full message ("filesystem error: cannot set current path: No such file or directory")
        << " (code: "
        << e.code().value()       // returns error code
        << ";"
        << e.code().message()     // returns only message ("No such file or directory")
        << ")\n";
        exit(1);
    }
}