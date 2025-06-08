/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 15:41:41 by jegerman          #+#    #+#             */
/*   Updated: 2025/06/08 17:10:59 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_nbr
{
	int				sign;
	unsigned long	nbr;
}	t_nbr;

#define B10 "0123456789"
#define B16L "0123456789abcdef"

int		ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
		++len;
	return (len);
}

void	ft_putchar_cc(char c, int *count)
{
	write(1, &c, 1);
	*count += 1;
}

void	ft_putstr_cc(const char *str, int *count)
{
	int	len;

	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	write(1, str, len);
	*count += len;
}

void	ft_putnbr_cc(t_nbr *nbr, char *base, int *count)
{
	unsigned long	radix;

	radix = ft_strlen(base);
	if (nbr->nbr >= radix)
		ft_putnbr_cc(&(t_nbr){nbr->sign, nbr->nbr / radix}, base, count);
	if (nbr->nbr < radix && nbr->sign)
		ft_putchar_cc('-', count);
	ft_putchar_cc(base[nbr->nbr % radix], count);
}

void	process_specifier(const char *str, int *i, va_list args, int *count)
{
	long			s_nbr;
	unsigned long	u_nbr;

	if (*str == 's')
		ft_putstr_cc(va_arg(args, char *), count);
	else if (*str == 'd')
	{
		s_nbr = va_arg(args, int);
		if (s_nbr < 0)
			ft_putnbr_cc(&(t_nbr){1, -s_nbr}, B10, count);
		else
			ft_putnbr_cc(&(t_nbr){0, s_nbr}, B10, count);
	}
	else if (*str == 'x')
	{
		u_nbr = va_arg(args, unsigned);
		ft_putnbr_cc(&(t_nbr){0, u_nbr}, B16L, count);
	}
	*i += 1;
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	int		i;

	va_start(args, str);
	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			process_specifier(str + ++i, &i, args, &count);
		else
			ft_putchar_cc(str[i++], &count);
	}
	va_end(args);
	return (count);
}

int	main(void)
{
	// printf("ft -> %i\n", ft_printf("12345\n"));
	// printf("ori -> %i\n", printf("12345\n"));
	// printf("ft -> %i\n", ft_printf("krkr%s|%s|lol\n", NULL, "a+"));
	// printf("ori -> %i\n", printf("krkr%s|%s|lol\n", (char *)0, "a+"));
	// printf("ft -> %i\n", ft_printf("[[%d||%d|%d\"\n", -2147483648, 41, 2147483647));
	// printf("ori -> %i\n", printf("[[%d||%d|%d\"\n", (int)-2147483648, 41, 2147483647));
	printf("ft -> %i\n", ft_printf("[[%x||%x|%x\"%x%x\n", -2147483648, 42, 2147483647, -1, 0));
	printf("ori -> %i\n", printf("[[%x||%x|%x\"%x%x\n", (int)-2147483648, 42, 2147483647, -1, 0));
}
