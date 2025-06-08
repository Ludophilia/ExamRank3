/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 17:34:44 by jegerman          #+#    #+#             */
/*   Updated: 2025/06/03 18:11:02 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdarg.h>
#include <unistd.h>

#define B10 "0123456789"
#define B16L "0123456789abcdef"

typedef struct s_nbr
{
	long			sign;
	unsigned long	nbr;
}	t_nbr;
