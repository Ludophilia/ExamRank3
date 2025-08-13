/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:51:30 by jegerman          #+#    #+#             */
/*   Updated: 2025/06/08 15:07:35 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

#include <stdarg.h>
#include <unistd.h>

#define B10 "0123456789"
#define B16L "0123456789abcdef"

#include <stdio.h>

typedef struct s_nbr
{
	int				sign;
	unsigned long	nbr;
}	t_nbr;

void	ft_putchar_cc(char c, int *count)
{
	write(1, &c, 1);
	*count += 1;
}

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
		++len;
	return (len);
}

void	ft_pustr_cc(char *str, int *count)
{
	int	str_len;

	if (str == NULL) // err - forgot to manage that case
		str = "(null)";
	str_len = ft_strlen(str);
	write(1, str, str_len);
	*count += str_len;
}

void	ft_putnbr_base_cc(t_nbr *nbr, char *base, int *count)
{
	unsigned long	radix;

	radix = ft_strlen(base);
	if (nbr->nbr >= radix)
		ft_putnbr_base_cc(&(t_nbr){nbr->sign, nbr->nbr / radix}, base, count);
	if (nbr->nbr < radix && nbr->sign)
		ft_putchar_cc('-', count);
	ft_putchar_cc(base[nbr->nbr % radix], count);
}

void	process_specifier(char *str, va_list args, int *i, int *count)
{
	long				s_nbr; // err - used int, which causes trouble for -2147483648
	unsigned long		u_nbr;

	if (*str == 's')
		ft_pustr_cc(va_arg(args, char *), count);
	else if (*str == 'd')
	{
		s_nbr = va_arg(args, int);
		if (s_nbr >= 0)
			ft_putnbr_base_cc(&(t_nbr){0, s_nbr}, B10, count);
		else
			ft_putnbr_base_cc(&(t_nbr){1, -s_nbr}, B10, count);
	}
	else if (*str == 'x')
	{
		u_nbr = va_arg(args, unsigned);
		ft_putnbr_base_cc(&(t_nbr){0, u_nbr}, B16L, count);
	}
	*i += 1;
}

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	args;
	int		i;
	
	va_start(args, str);
	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != '%')
			ft_putchar_cc(str[i++], &count);
		else
			process_specifier((char *)str + ++i, args, &i, &count);
	}
	va_end(args);
	return (count);
}

int	main(void)
{
	// printf("ft_count -> %i\n", ft_printf("%d\n", -2147483648));
	// printf("count -> %i\n", printf("%d\n", (int)-2147483648));
	// printf("ft_count -> %i\n", ft_printf("%s\n", (char *)"NULL"));
	// printf("count -> %i\n", printf("%s\n", (char *)"NULL"));
	// printf("ft_count -> %i\n", ft_printf("%x\n", -1));
	// printf("count -> %i\n", printf("%x\n", -1));
	// printf("ft_count -> %i\n", ft_printf("%x\n", -1));
	// printf("count -> %i\n", printf("%x\n", -1));
	printf("ft_count -> %i\n", ft_printf("012|%x|%d|%s|xx ...3\n", -1, -2147483648, (char *)0));
	printf("count -> %i\n", printf("012|%x|%d|%s|xx ...3\n", -1, (int)-2147483648, (char *)0));
}
