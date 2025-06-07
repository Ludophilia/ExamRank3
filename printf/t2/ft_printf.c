/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 16:29:04 by jegerman          #+#    #+#             */
/*   Updated: 2025/06/03 19:12:19 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		++len;
	return (len);
}

void	ft_putchar_cc(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

void	ft_putstr_cc(char *str, int *count)
{
	int	len;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		*count += 6;
	}
	else
	{
		len = ft_strlen(str);
		write(1, str, len);
		*count += len;
	}
}

void	ft_putnbr_base_cc(t_nbr *nbr, char *base, int *count)
{
	unsigned int	radix;

	radix = ft_strlen(base);
	if (nbr->nbr >= radix)
		ft_putnbr_base_cc(&(t_nbr){nbr->sign, nbr->nbr / radix}, base, count);
	if (nbr->nbr < radix && nbr->sign)
		ft_putchar_cc('-', count);
	ft_putchar_cc(base[nbr->nbr % radix], count);
}

void	process_specifier(const char *str, int *i, int *count, va_list args)
{
	long			s_nbr;
	unsigned long	u_nbr;

	if (*str == 's')
		ft_putstr_cc(va_arg(args, char *), count);
	else if (*str == 'd')
	{
		s_nbr = va_arg(args, int);
		if (s_nbr < 0)
			ft_putnbr_base_cc(&(t_nbr){.sign = 1, .nbr = -s_nbr}, B10, count);
		else
			ft_putnbr_base_cc(&(t_nbr){.sign = 0, .nbr = s_nbr}, B10, count);
	}
	else if (*str == 'x')
	{
		u_nbr = va_arg(args, unsigned int);
		ft_putnbr_base_cc(&(t_nbr){.sign = 0, .nbr = u_nbr}, B16L, count);
	}
	*i += 1;
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
			process_specifier(str + ++i, &i, &count, args);
		else
			ft_putchar_cc(str[i++], &count);
	}
	va_end(args);
	return (count);
}

#include <stdio.h>

int	main(void)
{
	// printf("(ft_count -> %i)\n", ft_printf("1\n"));
	// printf("(ft_count -> %i)\n", ft_printf("123\n"));
	// printf("(ft_count -> %i)\n", ft_printf("123456\n"));
	// printf("(ft_count -> %i)\n", ft_printf("0123456789\n"));
	// printf("(ft_count -> %i)\n", ft_printf("ABC%d%dDEF\n", 42, 43));
	// printf("(ft_count -> %i)\n", ft_printf("%d %d\n", 0x80000000, 2147483647));
	// printf("(ft_count -> %i)\n", ft_printf("%x\n", 0xFFFFFFFF));

	// printf("(ft_count -> %i)\n", ft_printf("ABC%s\n", (char *)0));
	// printf("(count -> %i)\n", printf("ABC%s\n", (char *)0));
	// ft_printf("ABC%x\n", 0x2a, );

	printf("(ft_count -> %i)\n",
		ft_printf("ABC%d%d%s%s%x%s\n", 42, 43, "oof", "waf", 0x2a, NULL));
	printf("(count -> %i)\n",
		printf("ABC%d%d%s%s%x%s\n", 42, 43, "oof", "waf", 0x2a, NULL));
}
