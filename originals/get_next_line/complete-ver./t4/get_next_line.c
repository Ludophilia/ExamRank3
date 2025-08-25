/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 17:40:57 by jegerman          #+#    #+#             */
/*   Updated: 2025/08/25 16:06:50 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	free_stash(char **stash)
{
	if (*stash == NULL)
		return (1);
	free(*stash);
	*stash = NULL;
	return (1);
}

int	get_nl_pos(char *stash)
{
	int	i;

	i = -1;
	while (stash[++i])
		if (stash[i] == '\n')
			return (i);
	return (-1);
}

char	*extract_line(char **stash)
{
	char	*line;
	int		stash_len;
	int		nl_pos;
	char	*new_stash;

	stash_len = ft_strlen(*stash);
	nl_pos = get_nl_pos(*stash);
	if (nl_pos + 1 == stash_len || nl_pos == -1)
	{
		line = *stash;
		*stash = NULL;
		return (line);
	}
	line = ft_substr(*stash, 0, (nl_pos + 1));
	if (line == NULL && free_stash(stash))
		return (NULL);
	new_stash = ft_substr(*stash, (nl_pos + 1), stash_len - (nl_pos + 1));
	if (new_stash == NULL && (free(line), free_stash(stash)))
		return (NULL);
	*stash = (free(*stash), new_stash);
	return (line); 
}

int	update_stash(int fd, char *buffer, char **stash)
{
	int		bytes;
	char	*new_stash;

	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes != -1)
		buffer[bytes] = 0; // Not a big deal, absolutely...
	if (bytes == 0 || (bytes == -1 && free_stash(stash)))
		return (bytes);
	if (*stash == NULL)
	{
		*stash = ft_strdup(buffer);
		if (*stash == NULL)
			return (-1);
		return (bytes);
	}
	new_stash = ft_strjoin(*stash, buffer);
	if (new_stash == NULL && free_stash(stash))
		return (-1);
	*stash = (free(*stash), new_stash);
	return (bytes);
}

char	*get_next_line(int fd)
{
	static char		*stash;
	char			*buffer;
	int				bytes;
	char			*line;
	
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL && free_stash(&stash))
		return (NULL);
	bytes = update_stash(fd, buffer, &stash);
	while (bytes > 0 && get_nl_pos(stash) == -1)
		bytes = update_stash(fd, buffer, &stash);
	free(buffer); // err - forgot to free that
	if (bytes == -1 || stash == NULL)
		return (NULL);
	line = extract_line(&stash);
	return (line);
}

/**
#include <fcntl.h>
#define MYFILE "my_file"
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open(MYFILE, O_RDONLY);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		// break;
		line = get_next_line(fd);
	}
	return (0);
}
*/