/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 13:23:10 by jegerman          #+#    #+#             */
/*   Updated: 2025/08/25 17:23:54 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE > 0 ? BUFFER_SIZE : 1];
	static int	bpos, bytes;
	char		*line;
	int			lpos;

	if (fd < 0 || BUFFER_SIZE < 1 || !(line = malloc(1 * 1024 * 1024)))
		return (NULL);
	lpos = 0;
	while (1)
	{
		if (bpos == 0 || bpos >= bytes)
		{
			if ((bytes = read(fd, buffer, BUFFER_SIZE)) == -1)
				return (free(line), NULL);
			if ((bpos > 0 && (bpos = 0)) || bytes == 0)
				break ;
		}
		while (bpos < bytes)
		{
			if ((line[lpos++] = buffer[bpos++]) == '\n')
				return (line[lpos] = 0, line);
		}
	}
	return (lpos > 0 ? (line[lpos] = 0, line) : (free(line), NULL));
}

// int	main(int argc, char **argv)
// {
// 	int		fd;
// 	char	*line;
	
// 	if (++argv, --argc != 1 && dprintf(2, "usage: ./gnl <file>\n"))
// 		return (1);
// 	fd = open(*argv, O_RDONLY);
// 	if (fd == -1)
// 		return (perror("Error"), 1);
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	return (0);
// }
