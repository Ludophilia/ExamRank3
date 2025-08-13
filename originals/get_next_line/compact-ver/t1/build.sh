#! /bin/bash

if [ -z $1 ]; then
	exit 1
fi

cc -Wall -Wextra -Werror -DBUFFER_SIZE=$1 -o gnl get_next_line.c

exit 0