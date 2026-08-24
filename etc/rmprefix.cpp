#include "rmprefix.h"
#include <string>

using namespace std;

char *rmprefix(char *text, char *prefix) {
    static string str = text;
    string pref = prefix;
#if __cplusplus >= 202002L
    if (
        str.starts_with(pref) // requires C++20 and higher
    ) {
        str.erase(0, pref.size()); // removes prefix
    }
#else
    // fallback for C++17 and older
    str.erase(0, pref.size());
#endif
    return str.data();
}