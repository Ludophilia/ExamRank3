/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:52:44 by jgermany          #+#    #+#             */
/*   Updated: 2024/01/08 19:28:32 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	swap_stash(char *buffer, char **stash)
{
	char	*stash_old;

	if (stash == NULL)
		return (-1);
	if (*stash == NULL)
	{
		*stash = my_strdup(buffer);
		if (*stash == NULL)
			return (-1);
	}
	else
	{
		stash_old = *stash;
		*stash = my_strjoin(stash_old, buffer);
		if (*stash == NULL)
		{
			free(stash_old);
			return (-1);
		}
		free(stash_old);
	}
	return (0);
}

int	update_stash(int fd, char **stash)
{
	char	buffer[BUFFER_SIZE + 1];
	int		bytesread;

	if (stash == NULL)
		return (-1);
	buffer[BUFFER_SIZE] = 0;
	bytesread = read(fd, buffer, BUFFER_SIZE);
	if (bytesread == -1 || (bytesread > 0 && swap_stash(buffer, stash) == -1))
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

char	*extract_line(char **stash)
{
	char	*line;
	int		nl_pos;
	char	*old_stash;

	if (stash == NULL || *stash == NULL)
		return (NULL);
	line = NULL;
	nl_pos = my_strchr('\n', *stash);
	if (nl_pos > -1)
	{
		old_stash = *stash;
		line = my_substr(*stash, 0, nl_pos + 1);
		*stash = my_substr(*stash, nl_pos, my_strlen(*stash) - nl_pos);
		if (line == NULL || *stash == NULL)
		{
			free(old_stash);
			*stash = NULL;
			return (NULL);
		}
		free(old_stash);
	}
	else
		line = *stash;
	return (line);
}

#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	int			bytesread;

	if (fd == -1 || BUFFER_SIZE < 1)
		return (NULL);
	line = NULL;
	stash = NULL;
	bytesread = update_stash(fd, &stash);
	if (bytesread == -1)
		return (NULL);
	// while (bytesread > 0 && my_strchr('\n', stash) == -1)
	// {
	// 	bytesread = update_stash(fd, &stash);
	// 	if (bytesread == -1)
	// 		return (NULL);	
	// }
	printf("stash: '%s'", stash);
	// if (my_strchr('\n', stash) != -1 || bytesread == 0)
	// 	line = extract_line(&stash);
	return (line);
}
