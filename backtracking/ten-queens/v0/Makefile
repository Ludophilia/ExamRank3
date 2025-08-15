# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jegerman <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/13 13:06:27 by jegerman          #+#    #+#              #
#    Updated: 2025/08/15 17:42:08 by jegerman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := queens

CC := cc
CFLAGS := -Wall -Wextra -Werror

SRCS := ten-queens.c

OBJS := $(SRCS:.c=.o)

all: $(NAME)
	$(CC) $(CFLAGS) -o $< $(OBJS)

$(NAME): $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)
	rm -rf solutions

re: fclean all

.PHONY: all clean fclean re
.SILENT: clean fclean