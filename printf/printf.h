/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:50:00 by jgermany          #+#    #+#             */
/*   Updated: 2024/01/10 14:41:47 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

#include <stdbool.h>
#include <stdint.h>

typedef struct s_nbr
{
	bool		sign;
	uint32_t	nbr;
}	t_nbr;

enum e_sign
{
	SIGN_POS = 0,
	SIGN_NEG
};

#define B10 "0123456789"
#define B16l "0123456789abcdef"

int	ft_printf(const char *str, ...);
