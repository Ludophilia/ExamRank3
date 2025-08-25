/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 16:34:19 by jegerman          #+#    #+#             */
/*   Updated: 2025/08/25 16:00:32 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*line, *buffer;

	if (BUFFER_SIZE < 1 || fd < 0 || !(buffer = line = malloc(20 * 1024)))
		return (NULL);
	while (read(fd, buffer, 1) > 0 && *buffer++ != '\n');
	return (buffer > line ? (*buffer = 0, line) : (free(line), NULL));
}
