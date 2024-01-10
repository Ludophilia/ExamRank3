/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:19:28 by jgermany          #+#    #+#             */
/*   Updated: 2024/01/10 16:52:02 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	my_strlen(const char *str)
{
	int	len;

	len = -1;
	while (str[++len])
		;
	return (len);
}

int	my_putchar(int c, int *count)
{
	if (count == NULL || write(1, &c, 1) == -1)
		return (-1);
	*count += 1;
	return (1);
}

int	my_putstr(const char *str, int *count)
{
	int	str_len;

	if (count == NULL)
		return (-1);
	if (str == NULL)
		str = "(null)";
	str_len = my_strlen(str);
	if (write(1, str, str_len) == -1)
		return (-1);
	*count += str_len;
	return (2);
}

int	my_putnbr(t_nbr *nbr, char *base, int *count)
{
	int	radix;

	if (nbr == NULL || base == NULL || count == NULL)
		return (-1);
	radix = my_strlen(base);
	if (radix < 1)
		return (-1);
	if (nbr->nbr >= radix
		&& my_putnbr(&(t_nbr){nbr->sign, nbr->nbr / radix}, base, count) == -1)
		return (-1);
	if ((nbr->nbr < radix && nbr->sign == S_NEG)
		&& my_putchar('-', count) == -1)
		return (-1);
	if (my_putchar(base[nbr->nbr % radix], count) == -1)
		return (-1);
	return (2);	
}

int	my_parse_spec(const char *str, va_list *args, int *count)
{
	int			off;
	int32_t		s_nbr;
	uint32_t	u_nbr;

	off = 0;
	if (str == NULL || args == NULL || count == NULL)
		return (-1);
	if (str[0 + 1] == ' ' || str[0 + 1] == '\0')
		return (-1);
	else if (str[0 + 1] == 's')
		off = my_putstr(va_arg(*args, char *), count);
	else if (str[0 + 1] == 'd')
	{
		s_nbr = va_arg(*args, int32_t);
		if (s_nbr < 0)
			off = my_putnbr(&(t_nbr){S_NEG, -s_nbr}, B10, count);
		else
			off = my_putnbr(&(t_nbr){S_POS, s_nbr}, B10, count);
	}
	else if (str[0 + 1] == 'x')
	{
		u_nbr = va_arg(*args, uint32_t);
		off = my_putnbr(&(t_nbr){S_POS, u_nbr}, B16l, count);
	}
	else
		off = my_putchar('%', count);
	if (off == -1)
		return (-1);
	return (off);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	args;
	int		i;
	int		off;

	if (str == NULL)
		return (-1);
	count = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
			off = my_parse_spec(str + i, &args, &count);
		else
			off = my_putchar(str[i], &count);
		if (off == -1)
			return (-1);
		i += off;
	}
	va_end(args);
	return (count);
}
