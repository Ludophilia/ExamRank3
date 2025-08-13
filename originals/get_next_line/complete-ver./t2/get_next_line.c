/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 13:21:59 by jegerman          #+#    #+#             */
/*   Updated: 2025/06/07 15:05:39 by jegerman         ###   ########.fr       */
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

int	update_stash(int fd, char *buffer, char **stash)
{
	int		bytes;
	char	*new_stash;
	
	bytes = read(fd, buffer, BUFFER_SIZE);
	if ((bytes == 0) || (bytes == -1 && free_stash(stash)))
		return (bytes);
	buffer[bytes] = 0;
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

int		get_nl_pos(char *stash)
{
	int nl_pos;

	if (stash == NULL)
		return (-1);
	nl_pos = -1;
	while (stash[++nl_pos])
	{
		if (stash[nl_pos] == '\n')
			return (nl_pos);
	}
	return (-1);
}

char	*extract_line(char **stash)
{
	char	*line;
	int		nl_pos;
	char	*new_stash;
	int		stash_len;

	nl_pos = get_nl_pos(*stash);
	stash_len = ft_strlen(*stash);
	if (nl_pos == -1 || (nl_pos + 1) == stash_len)
	{
		line = *stash;
		*stash = NULL;
		return (line);
	}
	line = ft_substr(*stash, 0, nl_pos + 1);
	if (line == NULL && free_stash(stash))
		return (NULL);
	new_stash = ft_substr(*stash, (nl_pos + 1), (stash_len - (nl_pos + 1))); 
	if (new_stash == NULL && (free(line), free_stash(stash)))
		return (NULL);
	*stash = (free(*stash), new_stash);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*buffer;
	int			bytes;
	
	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL && free_stash(&stash))
		return (NULL);
	bytes = update_stash(fd, buffer, &stash);
	while (bytes > 0 && get_nl_pos(buffer) == -1)
		bytes = update_stash(fd, buffer, &stash);
	free(buffer);
	if (bytes == -1 || stash == NULL)
		return (NULL);
	line = extract_line(&stash);
	return (line);
}