# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jegerman <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/13 13:06:27 by jegerman          #+#    #+#              #
#    Updated: 2025/08/17 16:31:27 by jegerman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := rip

CC := cc
CFLAGS := -Wall -Wextra -Werror

SRCS := rip.c

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