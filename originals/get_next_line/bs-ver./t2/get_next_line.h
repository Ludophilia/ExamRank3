/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 16:32:57 by jegerman          #+#    #+#             */
/*   Updated: 2025/06/07 16:45:42 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
 # define BUFFER_SIZE 10
#endif

char	*get_next_line(int fd);
