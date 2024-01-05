/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:00:47 by jgermany          #+#    #+#             */
/*   Updated: 2024/01/05 18:13:05 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char	*line;
	int		fd;

	fd = open(FL_3LINES, O_RDONLY);
	if (fd == -1)
		return (EXIT_FAILURE);
	line = get_next_line(fd);
	printf("%s", line);
	return (EXIT_SUCCESS);
}
