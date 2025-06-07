/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 12:53:41 by jegerman          #+#    #+#             */
/*   Updated: 2025/06/04 13:04:44 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*line, *buffer;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	line = malloc(20 * 1000), buffer = line;
	if (line == NULL)
		return (NULL);
	while (read(fd, buffer, 1) > 0 && *buffer++ != '\n')
		;
	return ((buffer > line)? (*buffer = 0, line) : (free(line), NULL));
}