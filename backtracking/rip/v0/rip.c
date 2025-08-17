/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rip.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 18:07:05 by jegerman          #+#    #+#             */
/*   Updated: 2025/08/17 19:22:23 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// bip for balance invalid parentheses
int	bip(char *str, int *rpr, int *lpr)
{
	int	i;

	i = -1;
	if (*str == 0)
		return (1);
	while (str[++i])
	{
		if (str[i] == '(')
			*rpr += 1;
		if (str[i] == ')' && *rpr == 0)
			*lpr += 1;
		if (str[i] == ')' && *rpr > 0)
			*rpr -= 1;
	}
	if (*rpr == 0 && *lpr == 0)
		return (1);
	return (0);
}

// rip for remove invalid parentheses
int	rip(int i, char *str, int rpr, int lpr)
{
	if (str[i] == 0)
	{
		bip(str, &rpr, &lpr) && printf("'%s'\n", str);
		return (0);
	}
	if (str[i] == '(' && rpr > 0)
	{
		str[i] = ' ';
		rip(i + 1, str, rpr - 1, lpr);
		str[i] = '(';
	}
	if (str[i] == ')' && lpr > 0)
	{
		str[i] = ' ';
		rip(i + 1, str, rpr, lpr - 1);
		str[i] = ')';
	}
	rip(i + 1, str, rpr, lpr);
	return (0);
}

int	main(int argc, char **argv)
{
	int	rpr;
	int	lpr;
	
	if (*(++argv) == NULL && --argc != 1)
		return (1);
	rpr = 0;
	lpr = 0;
	if (bip(*argv, &rpr, &lpr) && printf("'%s'\n", *argv))
		return (0);
	rip(0, *argv, rpr, lpr);
	return (0);
}
