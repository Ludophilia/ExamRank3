/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:13:17 by jegerman          #+#    #+#             */
/*   Updated: 2025/08/19 19:27:14 by jegerman         ###   ########.fr       */
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
		if (argv[i][j] == '+')
			++j;
		else if (argv[i][j] == '-')
			return (0);
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (0);
			++j;
		}
	}
	return (1);
}

static void	cli_swap(int *nbr1, int *nbr2)
{
	int tmp;

	tmp = *nbr1;
	*nbr1 = *nbr2;
	*nbr2 = tmp;
}

static int	cli_sort(int *nbr, int size)
{
	for (int i = 0; i < size - 1; i++)
		for (int j = i + 1; j < size; j++)
			if (nbr[i] > nbr[j])
				cli_swap(nbr + i, nbr + j);
	return (0);
}

int	*cli_parse(int argc, char **argv, int **nbrs_ptr, int *target)
{
	int	*nbrs;
	int i;

 	if (cli_validate(argc, argv) == 0)
		return (NULL);
	nbrs = malloc((argc - 1) * sizeof(int));
	if (nbrs == NULL)
		return (NULL);
	for (i = 0; i < argc - 1; ++i)
		nbrs[i] = cli_atoi(argv[i]);
	*target = cli_atoi(argv[i]);
	cli_sort(nbrs, argc - 1);
	*nbrs_ptr = nbrs;
	return (nbrs);
}
