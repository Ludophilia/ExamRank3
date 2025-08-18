/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 13:28:48 by jegerman          #+#    #+#             */
/*   Updated: 2025/08/18 19:36:50 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int	cli_atoi(char *str)
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

int	print_nbrs(int *nbrs, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (i == 0 && size == 1)
			printf("[%i]\n", nbrs[i]);
		else if (i == 0 && size != 1)
			printf("[%i,", nbrs[i]);
		else if (i == size - 1)
			printf("%i]\n", nbrs[i]);
		else
			printf("%i,", nbrs[i]);
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

void	swap(int *nb1, int *nb2)
{
	int	tmp;

	if (nb1 == nb2)
		return ;
	tmp = *nb1;
	*nb1 = *nb2;
	*nb2 = tmp;
}

int	permutate(int *nbrs, int at, int size)
{
	if ((at == size - 1) && print_nbrs(nbrs, size)) // ??
		return (0);
	for (int i = at; i < size; i++)
	{
		swap(nbrs + at, nbrs + i);
		permutate(nbrs, at + 1, size);
		swap(nbrs + at, nbrs + i);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	*nbrs;

	if ((++argv, --argc == 0)
		|| cli_validate(argc, argv) == false
		|| cli_parse(argc, argv, &nbrs) == NULL)
		return (1);
	argc == 1 && print_nbrs(nbrs, argc);
	argc > 1 && permutate(nbrs, 0, argc);
	free(nbrs);
	return (0);
}