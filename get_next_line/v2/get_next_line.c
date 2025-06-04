/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:43:29 by jegerman          #+#    #+#             */
/*   Updated: 2025/05/31 14:57:16 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "get_next_line.h"

#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd)
{
	char *line = malloc(20 * 1000), *buffer = line;
	
	if (BUFFER_SIZE < 1 || fd < 0)
		return (free(line), NULL);
	while (read(fd, buffer, 1) > 0 && *buffer++ != '\n')
		;
	return ((buffer > line)? (*buffer = 0, line) : (free(line), NULL));
}

// int		free_stash(char **stash)
// {
// 	if (stash == NULL || *stash == NULL)
// 		return (1);
// 	free(*stash);
// 	*stash = NULL;
// 	return (1);
// }

// int		get_nl_pos(char *stash)
// {
// 	int	i;

// 	i = -1;
// 	while (stash[++i])
// 		if (stash[i] == '\n')
// 			return (i); 
// 	return (-1);
// }

// long	update_stash(int fd, char *buffer, char **stash)
// {
// 	long	bytes;
// 	char	*new_stash;

// 	bytes = read(fd, buffer, BUFFER_SIZE);
// 	if ((bytes == -1 && free_stash(stash)) || bytes == 0)
// 		return (bytes);
// 	buffer[bytes] = 0;
// 	if (*stash == NULL)
// 	{
// 		*stash = ft_strdup(buffer);
// 		if (*stash == NULL)
// 			return (-1);
// 		return (bytes);
// 	}
// 	new_stash = ft_strjoin(*stash, buffer);
// 	if (new_stash == NULL && free_stash(stash))
// 		return (-1);
// 	*stash = (free(*stash), new_stash);
// 	return (bytes);
// }

// char	*extract_line(char **stash)
// {
// 	char	*line;
// 	int		stash_len;
// 	int		nl_pos;
// 	char	*new_stash;

// 	stash_len = ft_strlen(*stash);
// 	nl_pos = get_nl_pos(*stash);
// 	if (nl_pos == -1 || (nl_pos + 1) == stash_len)
// 	{
// 		line = *stash;
// 		*stash = NULL;
// 		return (line);
// 	}
// 	line = ft_substr(*stash, 0, (nl_pos + 1));
// 	if (line == NULL && free_stash(stash))
// 		return (NULL);
// 	new_stash = ft_substr(*stash, (nl_pos + 1), (stash_len - (nl_pos + 1)));
// 	if (new_stash == NULL && (free(line), free_stash(stash)))
// 		return (NULL);
// 	*stash = (free(*stash), new_stash);
// 	return (line);
// }

// char	*get_next_line(int fd)
// {
// 	static char		*stash;
// 	char			*line;
// 	char			*buffer;
// 	long			bytes;

// 	if (fd < 0 && BUFFER_SIZE < 0)
// 		return (NULL);
// 	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
// 	if (buffer == NULL && free_stash(&stash))
// 		return (NULL);
// 	bytes = update_stash(fd, buffer, &stash);
// 	while (bytes > 0 && get_nl_pos(stash) == -1)
// 		bytes = update_stash(fd, buffer, &stash);
// 	free(buffer);
// 	if (bytes == -1 || stash == NULL)
// 		return (NULL);
// 	line = extract_line(&stash);
// 	return (line);
// }

// #include <stdlib.h>
// #include <unistd.h>
// // #include <stdio.h>

// // 30/05 - Found on the internet. Interesting... but very hacky.
// char *get_next_line(int fd) 
// {
// 	if (BUFFER_SIZE < 1 || fd < 0 || read(fd, NULL, 0) < 0) {return (NULL);} //
// 	int bytes; char *line = malloc(20 * 1000), *buf = line;
// 	if (line == NULL) {return (NULL);}
// 	// \n
// 	// ABC| DEF|\n
// 	while ((bytes = read(fd, buf, 1)) > 0 && (*buf++ != '\n')) // even if out of the loop, we are AFTER the '\n'
// 		; // OK OK OK! If we read more than one, we don't really  know where the '\n' could be... Not necessarily 
// 		// at the end!!
// 	return (buf > line) ? (*buf = 0, line) : (free(line), NULL); // *buf = 0 means add a null character after the \n!
// }


// 30/05 - Found on the internet. Interesting... but very hacky.
// char *get_next_line(int fd) 
// {
// 	if (BUFFER_SIZE < 1 || fd < 0 || read(fd, NULL, 0) < 0) { return (NULL); }
// 	char *line = malloc(100000), *buf = line;
// 	while (read(fd, buf, 1) > 0 && *buf++ != '\n');
// 	return (buf > line) ? (*buf = 0, line) : (free(line), NULL);
// }


// #include <fcntl.h>

// int	main(void)
// {
// 	return (0);	
// }