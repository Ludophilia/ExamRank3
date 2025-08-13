# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jegerman <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/13 13:06:27 by jegerman          #+#    #+#              #
#    Updated: 2025/08/13 17:53:11 by jegerman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := 123

CC := cc
CFLAGS := -Wall -Wextra -Werror

SRCS := 123-swap.c

OBJS := $(SRCS:.c=.o)

all: $(NAME)
	$(CC) $(CFLAGS) -o $< $(OBJS)

$(NAME): $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
.SILENT: clean fclean