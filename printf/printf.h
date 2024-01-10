/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:16:39 by jgermany          #+#    #+#             */
/*   Updated: 2024/01/10 16:07:40 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

enum e_sign
{
	S_POS = 0,
	S_NEG
};

typedef struct s_nbr
{
	bool		sign;
	uint32_t	nbr;
}	t_nbr;

#define B10 "0123456789"
#define B16l "0123456789abcdef"

int	ft_printf(const char *str, ...);
