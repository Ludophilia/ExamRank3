#! /bin/bash

NAME="printf"

CC="cc"
CFLAGS="-Wall -Wextra -Werror"

SRCS="main.c"
SRCS+=" printf.c"

if [ "$1" = "debug" ]; then
	unset CFLAGS
fi

if [ $# -eq 0 ] || [ "$1" = "all" ] || [ "$1" = "debug" ]; then
	$CC $CFLAGS -I. -o $NAME $SRCS
elif [ "$1" = "fclean" ]; then
	rm -f $NAME
else
	echo "Invalid arguments."
fi
