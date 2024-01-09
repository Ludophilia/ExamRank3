/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:00:49 by jgermany          #+#    #+#             */
/*   Updated: 2024/01/09 18:49:38 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

// What should be done?

// 3 layers: printf > parser > printer

// - Iterate on str
// - If you see (%) time to get naughty
// - else, just write the character on the screen

int	my_putchar(char c, int *count)
{
	if (count == NULL || write(1, &c, 1) == -1)
		return (-1);
	*count += 1;
	return (1);
}

int	process_specif(const char *str, int *count)
{
	int	i;

	if (str == NULL || count == NULL)
		return (-1);
	i = 0;
	// Possible: %s, %d, %x
	if (str)
		;
	return (1);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	int		i;
	int		tmp;
	
	count = 0;
	va_start(args, str);

	if (str == NULL)
		return (-1);
	
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			tmp = process_specif(str + i, &count);
			if (tmp == -1)
				return (-1);
			i += tmp;
		}
		else
		{
			tmp = my_putchar(str[i], &count);
			if (tmp == -1)
				return (-1);
			i += tmp;
		}
	}
	va_end(args);
	return (count);
}
