# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jegerman <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/13 13:06:27 by jegerman          #+#    #+#              #
#    Updated: 2025/08/19 18:27:32 by jegerman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := queens

CC := cc
CFLAGS := -Wall -Wextra -Werror

SRCS := ten-queens.c

OBJS := $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)
	rm -rf solutions

re: fclean all

.PHONY: all clean fclean re
.SILENT: clean fclean