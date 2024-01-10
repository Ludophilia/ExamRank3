#! /bin/bash

NAME="get_next_line"

CC="cc"
CFLAGS="-Wall -Wextra -Werror"
# CFLAGS+= "-DBUFFER_SIZE=10" 

SRCS="main.c"
SRCS+=" get_next_line.c"
SRCS+=" get_next_line_utils.c"

INCL="."

if [ $# -eq 0 ] || [ $1 = "all"]; then
	$CC $CFLAGS -o $NAME -I$INCL $SRCS
elif [ $1 = "fclean" ]; then
	rm -f $NAME
else
	echo "Invalid argument."
fi
