/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:13:17 by jegerman          #+#    #+#             */
/*   Updated: 2025/08/19 15:14:54 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	cli_atoi(char *str)
{
	int	nbr;
	int	sign;

	nbr = 0;
	sign = 1;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	while (*str >= '0' && *str <= '9')
		nbr = 10 * nbr + *str++ - '0';
	return (sign * nbr);
}

int	cli_validate(int argc, char **argv)
{
	for (int i = 0, j; i < argc; i++)
	{
		j = 0;
		if (argv[i][j] == '+' || argv[i][j] == '-')
			++j;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (0);
			++j;
		}
	}
	return (1);
}

int	*cli_parse(int argc, char **argv, int **nbrs_ptr)
{
	int	*nbrs;

	nbrs = malloc(argc * sizeof(int));
	if (nbrs == NULL)
		return (NULL);
	for (int i = 0; i < argc; ++i)
		nbrs[i] = cli_atoi(argv[i]);
	*nbrs_ptr = nbrs;
	return (nbrs);
}
