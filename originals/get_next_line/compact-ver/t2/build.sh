#! /bin/bash

if [ -z $1 ]; then
	printf "usage ./build.sh <buffer_size>\n" > /dev/stderr
	exit 123
fi

cc -Wall -Wextra -Werror -DBUFFER_SIZE=$1 -o gnl get_next_line.c

exit 0