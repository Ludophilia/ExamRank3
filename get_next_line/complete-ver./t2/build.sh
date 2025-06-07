# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    build.sh                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jegerman <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/07 13:25:01 by jegerman          #+#    #+#              #
#    Updated: 2025/06/07 13:51:14 by jegerman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

NAME="get_next_line"

CFLAGS="-Wall -Wextra -Werror -g3"

SRCS="get_next_line.c get_next_line_utils.c main.c"

INCL_DIR="."

cc $CFLAGS -I$INCL_DIR -o $NAME $SRCS
