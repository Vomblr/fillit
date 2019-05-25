#!/usr/bin/env bash


 clang -Wall -Wextra -Werror -o functions.o -c sources/functions.c
 clang -Wall -Wextra -Werror -o error.o -c sources/error.c
 clang -Wall -Wextra -Werror -o main.o -c sources/main.c
 clang -Wall -Wextra -Werror -o test_valid functions.o main.o error.o
rm -f main.o functions.o error.o