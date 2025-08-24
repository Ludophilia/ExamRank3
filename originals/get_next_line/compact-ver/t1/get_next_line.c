/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 13:23:10 by jegerman          #+#    #+#             */
/*   Updated: 2025/08/24 22:32:15 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// 13/06 - Goal: improve the bs_ver so it can correctly manage a variable buffer size...
// That version tries to just correctly manage a variable BUFFER_SIZE read size.

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE > 0 ? BUFFER_SIZE : 1];
	static int	bpos, bytes;
	char		*line;
	int			lpos, no_nl;

	if (fd < 0 || BUFFER_SIZE < 1 || !(line = malloc(1 * 512)))
		return (NULL);
	lpos = 0;
	no_nl = 1;
	while (1)
	{
		if (bpos == 0 || bpos >= bytes)
		{
			if ((bytes = read(fd, buffer, BUFFER_SIZE)) == -1)
				return (free(line), NULL);
			bpos && (bpos = 0);
		}
		while (bpos < bytes)
		{
			if ((line[lpos++] = buffer[bpos++]) == '\n')
			{
				no_nl = 0;
				break ;
			}
		}
		if (bytes == 0)
			break ;
	}
	// return (free(line), NULL);
	return (lpos > 0 ? (line[lpos] = 0, line) : (free(line), NULL));
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
int	main(void)
{
	int		fd;
	char	*line;

	fd = open(FILE, O_RDONLY);
	if (fd == -1)
		return (perror(NULL), 1);
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

// ========================================================================

// char	*troll_next_line(int fd)
// {
// 	char	*line, *buffer;

// 	if (fd < 0 || BUFFER_SIZE < 1 || !(buffer = line = malloc(1 * 56)))
// 		return (NULL);
// 	while (read(fd, buffer, 1) > 0 && *buffer++ != '\n');
// 	return ((buffer > line) ? (*buffer = 0, line): (free(line), NULL));
// }

// ========================================================================

// char	*get_next_line(int fd)
// {
// 	static char	buf[BUFFER_SIZE]; // Buffer and trackers are kept between calls.
// 	static int	i = 0, r = 0;
// 	char		*line;
// 	int			j = 0;

// 	if (fd < 0 || BUFFER_SIZE <= 0 || !(line = malloc(10000)))
// 		return (NULL);
// 	while (1)
// 	{
//		// read at start (i = 0, r = 0;) ; then again when buffer is full.
// 		if (i >= r)
// 		{
// 			i = 0;
// 			r = read(fd, buf, BUFFER_SIZE);
// 			if (r < 1) // if there is nothing else to read or something wrong occured.
// 				break ;
// 		}
//		//
// 		line[j++] = buf[i++];
// 		if (line[j - 1] == '\n')
// 			break ;
// 	}
// 	return (j ? (line[j] = 0, line) : (free(line), NULL));
// }

// ========================================================================

// long	get_nl_pos(char	*buffer, long bytes)
// {
// 	long	i;

// 	i = -1;
// 	while (++i < bytes)
// 		if (buffer[i] == '\n')
// 			return (i);
// 	return (-1);
// }

// char	*get_next_line(int fd)
// {
// 	char	*line, *buffer;
// 	long	bytes, nl_pos;

// 	if (fd < 0 || BUFFER_SIZE < 1
// 		|| !(buffer = line = malloc(1 * 1000 * 1000)))
// 		return (NULL);
// 	nl_pos = -1;
// 	printf("[[buffer start -> \"%s\"\n", buffer);

// 	while ((bytes = read(fd, buffer, BUFFER_SIZE)) > 0
// 			&& (nl_pos = get_nl_pos(buffer, bytes)) == -1)
// 	{
// 		printf("(%li) buffer mid -> \"%s\"\n", bytes, buffer);
// 		buffer += bytes;
// 		nl_pos = -1;
// 	}
// 	printf("(%li) buffer end -> \"%s\"\n", bytes, buffer);
// 	buffer += (nl_pos != -1) ? (nl_pos + 1) : 0;
// 	printf("buffer end -> \"%s\"]]\n", buffer);
// 	return ((buffer > line) ? (*buffer = 0, line): (free(line), NULL));
// }

