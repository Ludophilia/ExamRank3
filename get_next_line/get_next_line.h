/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:01:43 by jgermany          #+#    #+#             */
/*   Updated: 2024/01/05 18:25:31 by jgermany         ###   ########.fr       */
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

char	*get_next_line(int fd);
