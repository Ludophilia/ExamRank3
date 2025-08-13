/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:43:29 by jegerman          #+#    #+#             */
/*   Updated: 2025/06/07 16:11:02 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char *line = malloc(20 * 1000), *buffer = line;
	
	if (BUFFER_SIZE < 1 || fd < 0)
		return (free(line), NULL);
	while (read(fd, buffer, 1) > 0 && *buffer++ != '\n')
		;
	return ((buffer > line)? (*buffer = 0, line) : (free(line), NULL));
}

// // 30/05 - Found on the internet. Interesting... but very hacky.
// char *get_next_line(int fd) 
// {
// 	if (BUFFER_SIZE < 1 || fd < 0 || read(fd, NULL, 0) < 0) {return (NULL);} //
// 	int bytes; char *line = malloc(20 * 1000), *buf = line;
// 	if (line == NULL) {return (NULL);}
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
