cmake_minimum_required(VERSION 3.20)

project(fastshell C CXX)

add_executable(fastshell
    main.c call.c input.c
    commands/sh.c commands/cycle.cpp commands/help.c
    commands/whoami.c commands/reload.c
    commands/pwd.cpp
    etc/isdbg.c etc/panic.cpp etc/expanduser.c
    etc/dirs.cpp etc/rmprefix.cpp
)

target_compile_options(fastshell PRIVATE
    -Wall -Wextra -Wpedantic                 # https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html
)

if (DEFINED WARNS_AS_ERRS)
    target_compile_options(fastshell PRIVATE -Werror)
endif()
