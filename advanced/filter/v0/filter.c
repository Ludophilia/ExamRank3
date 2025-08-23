/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 14:40:27 by jegerman          #+#    #+#             */
/*   Updated: 2025/08/23 16:26:53 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
 # define BUFFER_SIZE 10
#endif

char	*get_next_line(int fd)
{
	char	*line, *buffer;
	long	bytes;

	if (fd < 0 || BUFFER_SIZE < 1
		|| (!(buffer = line = malloc(20 * 1000)) && (perror("Error"), 1)))
		return (NULL);
	while ((bytes = read(fd, buffer, 1)) > 0 && *buffer++ != '\n')
		;
	if (bytes == -1 && (perror("Error"), 1))
		return (free(line), NULL);
	return (buffer > line? (*buffer = 0, line): (free(line), NULL));
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		++len;
	return (len);
}

int	check_str(char *line, char *clear)
{
	int	j;

	j = 0;
	while (line[j] && line[j] == clear[j])
	{
		if (clear[j + 1] == 0)
			return (1);
		++j;
	}
	return (0);
}

int	replace_str(char *line, char *clear)
{
	int	len;

	len = ft_strlen(clear);
	for (int j = 0; j < len; j++)
		line[j] = '*';
	return (len);
}

char	*filter(char *clear)
{
	char	*line;
	int		i;
	
	line = get_next_line(0);
	i = 0;
	while (line[i])
	{
		if (check_str(line + i, clear))
			i += replace_str(line + i, clear);
		else
			i++;
	}
	return (line);
}

int	main(int argc, char **argv)
{
	char	*line;

	if ((++argv, --argc) != 1)
		return (1);
	line = filter(*argv);
	printf("%s", line);
	free(line);
	return (0);
}
