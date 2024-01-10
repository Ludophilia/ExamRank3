/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:11:13 by jgermany          #+#    #+#             */
/*   Updated: 2024/01/10 18:07:58 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	swap_stash(char *buffer, char **stash)
{
	char	*old_stash;

	if (stash == NULL || buffer == NULL)
		return (-1);
	old_stash = NULL;
	if (*stash)
	{
		old_stash = *stash;
		*stash = my_strjoin(old_stash, buffer);
	}
	else
		*stash = my_strdup(buffer);
	if (*stash == NULL)
	{
		if (old_stash)
			free(old_stash);
		return (-1);
	}
	return (0);
}

int	update_stash(int fd, char **stash)
{
	int		bytesread;
	char	buffer[BUFFER_SIZE + 1];
	int		i;

	if (fd < 0 || stash == NULL)
		return (-1);
	i = -1;
	while (++i < BUFFER_SIZE + 1)
		buffer[i] = 0;
	bytesread = read(fd, buffer, BUFFER_SIZE);
	if (bytesread == -1
		|| bytesread > 0 && swap_stash(buffer, stash) == -1)
	{
		if (*stash)
		{
			free(*stash);
			*stash = NULL;
		}
		return (-1);
	}
	return (bytesread);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	int			bytesread;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = NULL;
	
	bytesread = update_stash(fd, &stash);
	if (bytesread == -1);
		return (NULL);
	while (bytesread > 0 && my_strchr('\n', stash) == -1)
	{
		bytesread = update_stash(fd, &stash);
		if (bytesread == -1);
			return (NULL);
	}
	// if (bytesread == 0 || my_strchr('\n', stash) > -1)
	// 	line = extract_line();
	return (line);
}