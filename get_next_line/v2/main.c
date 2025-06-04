/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:00:47 by jgermany          #+#    #+#             */
/*   Updated: 2024/01/09 17:31:08 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

#define FL_GNL "get_next_line.c"
#define FL_GROUP "/etc/group"
#define FL_EMPTY "empty"
#define FL_THREE "threelines"
#define FL_BUILD "build.sh"
#define FL_NEWLINES "newlines"
#define FL_RANDOM "/dev/random"
#define FL_STDIN "/dev/stdin"

int	main(void)
{
	char	*line;
	int		fd;

	fd = open(FL_GNL, O_RDONLY);
	if (fd == -1)
		return (EXIT_FAILURE);
	do
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	} while (line != NULL);
	return (EXIT_SUCCESS);
}
