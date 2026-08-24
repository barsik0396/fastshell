cmake_minimum_required(VERSION 3.20)

project(fastshell C CXX)

add_executable(fastshell
    main.c call.c input.c
    commands/sh.c commands/cycle.cpp commands/help.c
    etc/isdbg.c etc/panic.cpp etc/expanduser.c
)

target_compile_options(fastshell PRIVATE
    -Wall -Wextra -Wpedantic
)
