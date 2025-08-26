/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 14:40:27 by jegerman          #+#    #+#             */
/*   Updated: 2025/08/26 21:28:51 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE > 0 ? BUFFER_SIZE : 1];
	static int	bpos, bytes;
	char		*line;
	int			lpos;

	if (fd < 0 || BUFFER_SIZE < 1
		|| (!(line = malloc(1024)) && (perror("Error"), 1)))
		return (NULL);
	lpos = 0;
	while (1)
	{
		if (bpos == 0 || bpos >= bytes)
		{
			if ((bytes = read(fd, buffer, BUFFER_SIZE)) == -1)
				return (perror("Error"), free(line), NULL);
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

int	test_for_filter(char *str, char *fltr)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == fltr[i])
	{
		if (fltr[i++ + 1] == 0)
			return (1);
	}
	return (0);
}

int	replace(char *str, char *fltr)
{
	int	j;

	j = 0;
	while (fltr[j])
	{
		str[j++] = '*';
	}
	return (j);
}

char	*filter(char *fltr)
{
	char	*line;
	int		i;

	line = get_next_line(0);
	if (line == NULL)
		return (NULL);
	i = 0;
	while (line[i])
	{
		if (test_for_filter(line + i, fltr))
			i += replace(line + i, fltr);
		else
			i++;
	}
	return (line);
}

int	main(int argc, char **argv)
{
	char	*line;

	if (++argv, --argc != 1)
		return (1);
	line = filter(*argv);
	if (line == NULL)
		return (2);
	printf("%s", line);
	free(line);
	return (0);
}
