#! /bin/bash

NAME="get_next_line"

CC="cc"
CFLAGS="-Wall -Wextra -Werror"

SRCS="get_next_line.c"
SRCS+=" get_next_line_utils.c"
SRCS+=" main.c"

if [ $# -eq 0 ] || [ $1 = "all" ]; then
	$CC $CFLAGS $SRCS -o $NAME -I. 
elif [ $1 = "fclean" ]; then
	rm -f $NAME
else
	echo "Invalid argument"
	exit 1
fi
