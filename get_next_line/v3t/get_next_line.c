/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:43:29 by jegerman          #+#    #+#             */
/*   Updated: 2025/05/31 15:20:37 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char *line, *buffer;
	
	if (BUFFER_SIZE < 1 || fd < 0 || !(line = malloc(20 * 1000))
		|| !(buffer = line))
		return (NULL);
	while (read(fd, buffer, 1) > 0 && *buffer++ != '\n')
		;
	return ((buffer > line)? (*buffer = 0, line) : (free(line), NULL));
}

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE];
	static int	i = 0, r = 0;
	char		*line;
	int			j = 0;

	if (fd < 0 || BUFFER_SIZE <= 0 || !(line = malloc(10000)))
		return (NULL);
	while (1)
	{
		if (i >= r)
		{
			i = 0;
			r = read(fd, buf, BUFFER_SIZE);
			if (r < 1)
				break ;
		}
		line[j++] = buf[i++];
		if (line[j - 1] == '\n')
			break ;
	}
	return (j ? (line[j] = 0, line) : (free(line), NULL));
}