/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 13:23:10 by jegerman          #+#    #+#             */
/*   Updated: 2025/06/13 21:04:28 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
 # define BUFFER_SIZE 10
#endif

// 13/06 - Goal: improve the bs_ver so it can correctly manage a variable buffer size...
// That version tries to just correctly manage a variable BUFFER_SIZE read size.

long	get_nl_pos(char	*buffer, long bytes)
{
	long	i;

	i = -1;
	while (++i < bytes)
		if (buffer[i] == '\n')
			return (i);
	return (-1);
}

char	*get_next_line(int fd)
{
	char	*line, *buffer;
	long	bytes, nl_pos;

	if ((fd < 0)
		|| (BUFFER_SIZE < 1)
		|| !(line = malloc(1 * 1000 * 1000))
		|| !(buffer = line))
		return (NULL);
	nl_pos = -1;
	printf("[[buffer start -> \"%s\"\n", buffer);
	// read keep its positions between calls. so once it's read, it's read...
	// unless you lseek to correct it... But you cannot use it most of the TIME.
	// so it's difficult to read 
	while ((bytes = read(fd, buffer, BUFFER_SIZE)) > 0
			&& (nl_pos = get_nl_pos(buffer, bytes)) == -1)
	{
		printf("(%li) buffer mid -> \"%s\"\n", bytes, buffer);
		buffer += bytes;
		nl_pos = -1;
	}
	printf("(%li) buffer end -> \"%s\"\n", bytes, buffer);
	buffer += (nl_pos != -1) ? (nl_pos + 1) : 0;
	printf("buffer end -> \"%s\"]]\n", buffer);
	return ((buffer > line) ? (*buffer = 0, line): (free(line), NULL));
}

#include <fcntl.h>
#define FILE "file"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open(FILE, O_RDONLY);
	if (fd == -1 && fprintf(stderr, "Oh no.\n"))
		return (1);
	line = get_next_line(fd);
	// printf("%s", line);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}

// ========================================================================

// char	*get_next_line(int fd)
// {
// 	static char	buf[BUFFER_SIZE]; // Buffer and trackers are kept between calls 
// 	static int	i = 0, r = 0; // Implied by static. 
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
// 		line[j++] = buf[i++];
// 		if (line[j - 1] == '\n')
// 			break ;
// 	}
// 	return (j ? (line[j] = 0, line) : (free(line), NULL));
// }

// ========================================================================

// char	*get_next_line(int fd)
// {
// 	char	*line, *buffer;
	
// 	if (fd < 0
// 		|| BUFFER_SIZE < 1
// 		|| !(line = malloc(20 * 1000))
// 		|| !(buffer = line))
// 		return (NULL);
// 	while ((read(fd, buffer, 1) > 0) && (*buffer++ != '\n'))
// 		;
// 	return ((buffer > line) ? (*buffer = 0, line): (free(line), NULL));
// }
