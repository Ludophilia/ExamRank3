/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:00:47 by jgermany          #+#    #+#             */
/*   Updated: 2024/01/09 13:26:09 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char	*line;
	int		fd;

	fd = open(FL_GNL_C, O_RDONLY);
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
