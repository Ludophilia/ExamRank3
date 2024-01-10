/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:00:49 by jgermany          #+#    #+#             */
/*   Updated: 2024/01/10 14:56:23 by jgermany         ###   ########.fr       */
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

int	my_putchar(char c, int *count)
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

	radix = my_strlen(base);
	if (radix == -1)
		return (-1);
	if (nbr->nbr >= radix
		&& my_putnbr(&(t_nbr){nbr->sign, nbr->nbr / radix}, base, count) == -1)
		return (-1);
	if (nbr->nbr < radix && nbr->sign == SIGN_NEG
		&& my_putchar('-', count) == -1)
		return (-1);
	if (my_putchar(base[nbr->nbr % radix], count) == -1)
		return (-1);
	return (2);
}

int	process_specif(const char *str, va_list *args, int *count)
{
	int			i;
	int			tmp_i;
	int32_t		s_nbr;
	uint32_t	u_nbr;

	if (str == NULL || args == NULL || count == NULL)
		return (-1);
	i = 0;
	tmp_i = 0;
	if (str[1] == ' ' || str[1] == '\0')
		return (-1);
	else if (str[1] == 's')
		tmp_i = my_putstr(va_arg(*args, char *), count);
	else if (str[1] == 'd')
	{
		s_nbr = va_arg(*args, int32_t);
		if (s_nbr < 0)
			tmp_i = my_putnbr(&(t_nbr){SIGN_NEG, -s_nbr}, B10, count);
		else
			tmp_i = my_putnbr(&(t_nbr){SIGN_POS, s_nbr}, B10, count);
	}
	else if (str[1] == 'x')
	{
		u_nbr = va_arg(*args, uint32_t);
		tmp_i = my_putnbr(&(t_nbr){SIGN_POS, u_nbr}, B16l, count);
	}
	else
		tmp_i = my_putchar('%', count);
	if (tmp_i == -1)
		return (-1);
	i += tmp_i;
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	int		i;
	int		tmp;
	
	if (str == NULL)
		return (-1);
	va_start(args, str);
	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			tmp = process_specif(str + i, &args, &count);
		else
			tmp = my_putchar(str[i], &count);
		if (tmp == -1)
			return (-1);
		i += tmp;
	}
	va_end(args);
	return (count);
}
