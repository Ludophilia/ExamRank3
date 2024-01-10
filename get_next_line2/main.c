/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:01:56 by jgermany          #+#    #+#             */
/*   Updated: 2024/01/10 17:13:26 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

#define FL_GROUP "/etc/group"
#define FL_RANDOM "/dev/random"
#define FL_BUILD "build.sh"
#define FL_THREELINES "threelines"
#define FL_EMPTY "empty"
#define FL_GNL "get_next_line.c"

int	main(void)
{
	char	*line;
	int		fd;
	
	fd = open(FL_GROUP, O_RDONLY);
	if (fd == -1)
		return (1);

	line = get_next_line(fd);
	printf("%s", line);
	// free(line);

	return (0);
}