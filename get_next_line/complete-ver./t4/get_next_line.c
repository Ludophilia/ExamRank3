/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 17:40:57 by jegerman          #+#    #+#             */
/*   Updated: 2025/06/08 19:48:47 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		++len;
	return (len);
}

char	*ft_strdup(char *str)
{
	char	*dupl;
	int		str_len;
	int		i;

	str_len = ft_strlen(str);
	dupl = malloc((str_len + 1) * sizeof(char));
	if (dupl == NULL)
		return (NULL);
	i = -1;
	while (str[++i])
		dupl[i] = str[i];	
	dupl[i] = 0;
	return (dupl);
}

char	*ft_substr(char *str, unsigned start, unsigned len)
{
	char		*sub;
	unsigned	sub_len;
	unsigned	str_len;
	unsigned	i;

	str_len = ft_strlen(str);
	sub_len = 0;
	while (start + sub_len < str_len && sub_len < len)
		++sub_len;
	sub = malloc((sub_len + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (i < sub_len)
	{
		sub[i] = str[start + i];
		++i;
	}
	sub[i] = 0;
	return (sub);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	int		len[2];
	int		i;
	
	len[0] = ft_strlen(s1);
	len[1] = ft_strlen(s2);
	join = malloc((len[0] + len[1] + 1) * sizeof(char));
	if (join == NULL)
		return (NULL);
	i = -1;
	while (s1[++i])
		join[i] = s1[i];
	--i;
	while (s2[++i - len[0]])
		join[i] = s2[i - len[0]];
	join[i] = 0;
	return (join);
}

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
	if (bytes == 0 || (bytes == -1 && free_stash(stash)))
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