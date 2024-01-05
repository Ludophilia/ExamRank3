/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:52:44 by jgermany          #+#    #+#             */
/*   Updated: 2024/01/05 18:34:16 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// HERE WE GO AGAIN, THIRD TIME...

// What should be done?

// Principle

// 1 - Read BUFFER_SIZE bytes from the fd and store them into the buffer
//	- if bytesread == -1, definitely an error 
//	- if bytesread == 0, that's EOF, what should be done?
//	- if bytesread > 0, how you should store this shit in the stash

// 2 - Update your stash with the content of the buffer 

// 3 - Keep reading and updating until you see a NEWLINE or EOF

// 4 - Extract the line if your are at a NEWLINE or EOF

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	char		*buffer[BUFFER_SIZE + 1];
	int			bytesread;

	if (fd == -1 || BUFFER_SIZE < 1)
		return (NULL);
	line = NULL;
	stash = NULL;

	

	return (NULL);
}