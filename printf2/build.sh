#! /bin/bash

NAME="printf"

CC="cc"
CFLAGS="-Wall -Wextra -Werror"
unset CFLAGS

SRCS="main.c"
SRCS+=" printf.c"

if [ $# -eq 0 ] || [ $1 = "all" ]; then
	$CC $CFLAGS -o $NAME $SRCS
elif [ $1 = "fclean" ]; then
	rm -f $NAME
else
	echo "Invalid argument."
fi
