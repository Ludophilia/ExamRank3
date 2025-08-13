#! /bin/bash

printf "(BUFFER_SIZE -> $1)\n\n"
cc -Wall -Wextra -Werror -g3 -o gnl -DBUFFER_SIZE$1 -I. get_next_line.c