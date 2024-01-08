/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:01:43 by jgermany          #+#    #+#             */
/*   Updated: 2024/01/08 19:22:51 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
	# define BUFFER_SIZE 10
#endif

#define FL_3LINES "threelines"
#define FL_EMPTY "empty"
#define FL_RANDOM "/dev/random"
#define FL_GROUPS "/etc/group"
#define FL_BUILD_SH "build.sh"
#define FL_GNL_C "get_next_line.c"

int		my_strlen(char *str);
int		my_strchr(int c, char *str);
char	*my_strdup(char *str);
char	*my_strjoin(char *str1, char *str2);
char	*my_substr(char *str, int start, int len);

char	*get_next_line(int fd);
