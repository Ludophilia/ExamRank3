# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jegerman <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/13 13:06:27 by jegerman          #+#    #+#              #
#    Updated: 2025/08/18 19:39:58 by jegerman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := prms

CC := cc
CFLAGS := -Wall -Wextra -Werror

SRCS := permutations.c

OBJS := $(SRCS:.c=.o)

all: $(NAME)
	$(CC) $(CFLAGS) -o $< $(OBJS)

$(NAME): $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SILENT: clean fclean
