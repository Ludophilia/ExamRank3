/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 13:23:10 by jegerman          #+#    #+#             */
/*   Updated: 2025/08/25 15:54:06 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*troll_next_line(int fd)
{
	char	*line, *buffer;

	if (fd < 0 || BUFFER_SIZE < 1 || !(buffer = line = malloc(1 * 56)))
		return (NULL);
	while (read(fd, buffer, 1) > 0 && *buffer++ != '\n');
	return ((buffer > line) ? (*buffer = 0, line): (free(line), NULL));
}

// 25/08 - Wow. Pass all non strict francinette testcases. Not bad at all...
char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE > 0 ? BUFFER_SIZE : 1];
	static int	bpos, bytes;
	char		*line;
	int			lpos, no_nl;

	if (fd < 0 || BUFFER_SIZE < 1 || !(line = malloc(1 * 20 * 1024)))
		return (NULL);
	lpos = 0;
	no_nl = 1;
	while (no_nl)
	{
		if (bpos == 0 || bpos >= bytes)
		{
			if ((bytes = read(fd, buffer, BUFFER_SIZE)) == -1)
				return (free(line), NULL);
			if (bytes == 0)
				break ;
			(void)(bpos > 0 && (bpos = 0));
		}
		while (bpos < bytes)
		{
			if ((line[lpos++] = buffer[bpos++]) == '\n')
			{
				no_nl = 0;
				break ;
			}
		}
	}
	return (lpos > 0 ? (line[lpos] = 0, line) : (free(line), NULL));
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	
	if (++argv, --argc != 1 && dprintf(2, "usage: ./gnl <file>\n"))
		return (1);
	fd = open(*argv, O_RDONLY);
	if (fd == -1)
		return (perror("Error"), 1);
	line = get_next_line(fd);
	// printf("%s", line);
	// free(line);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}

// 25/08 - THere are lines to gain, but something is missing...
// char	*get_next_line(int fd)
// {
// 	static char	buffer[BUFFER_SIZE > 0 ? BUFFER_SIZE : 1];
// 	static int	bpos, bytes;
// 	char		*line;
// 	int			lpos;//, no_nl;

// 	if (fd < 0 || BUFFER_SIZE < 1 || !(line = malloc(1 * 512)))
// 		return (NULL);
// 	lpos = 0;
// 	// no_nl = 1;
// 	while (1)
// 	{
// 		if (bpos == 0 || bpos >= bytes)
// 		{
// 			if ((bytes = read(fd, buffer, BUFFER_SIZE)) == -1)
// 				return (free(line), NULL);
// 			bpos && (bpos = 0);
// 		}
// 		while (bpos < bytes)
// 		{
// 			if ((line[lpos++] = buffer[bpos++]) == '\n')
// 				return ((line[lpos] = 0, line));
// 			// {
// 			// 	no_nl = 0;
// 			// 	break ;
// 			// }
// 		}
// 		if (bytes == 0)
// 			break ;
// 	}
// 	return (free(line), NULL);
// 	// return (lpos > 0 ? (line[lpos] = 0, line) : (free(line), NULL));
// }
