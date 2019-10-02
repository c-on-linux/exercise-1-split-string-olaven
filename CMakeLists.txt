cmake_minimum_required(VERSION 3.10)
project(c_on_linux_ex1 C)

set(CMAKE_C_STANDARD 11)

add_executable(c_on_linux_ex1 main.c)
target_compile_options(c_on_linux_ex1 PRIVATE -Wall -Wextra -pedantic -Werror)