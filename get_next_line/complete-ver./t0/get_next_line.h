/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:01:43 by jgermany          #+#    #+#             */
/*   Updated: 2024/01/09 17:31:00 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
	# define BUFFER_SIZE 20
#endif

int		my_strlen(char *str);
int		my_strchr(int c, char *str);
char	*my_strdup(char *str);
char	*my_strjoin(char *str1, char *str2);
char	*my_substr(char *str, int start, int len);

char	*get_next_line(int fd);
