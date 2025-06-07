/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:43:29 by jegerman          #+#    #+#             */
/*   Updated: 2025/06/07 15:53:22 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		free_stash(char **stash)
{
	if (stash == NULL || *stash == NULL)
		return (1);
	free(*stash);
	*stash = NULL;
	return (1);
}

int		get_nl_pos(char *stash)
{
	int	i;

	i = -1;
	while (stash[++i])
		if (stash[i] == '\n')
			return (i); 
	return (-1);
}

long	update_stash(int fd, char *buffer, char **stash)
{
	long	bytes;
	char	*new_stash;

	bytes = read(fd, buffer, BUFFER_SIZE);
	if ((bytes == -1 && free_stash(stash)) || bytes == 0)
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

char	*extract_line(char **stash)
{
	char	*line;
	int		stash_len;
	int		nl_pos;
	char	*new_stash;

	stash_len = ft_strlen(*stash);
	nl_pos = get_nl_pos(*stash);
	if (nl_pos == -1 || (nl_pos + 1) == stash_len)
	{
		line = *stash;
		*stash = NULL;
		return (line);
	}
	line = ft_substr(*stash, 0, (nl_pos + 1));
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
	static char		*stash;
	char			*line;
	char			*buffer;
	long			bytes;

	if (fd < 0 && BUFFER_SIZE < 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL && free_stash(&stash))
		return (NULL);
	bytes = update_stash(fd, buffer, &stash);
	while (bytes > 0 && get_nl_pos(stash) == -1)
		bytes = update_stash(fd, buffer, &stash);
	free(buffer);
	if (bytes == -1 || stash == NULL)
		return (NULL);
	line = extract_line(&stash);
	return (line);
}
