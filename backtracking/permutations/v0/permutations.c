/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 13:28:48 by jegerman          #+#    #+#             */
/*   Updated: 2025/08/19 15:17:31 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
	int	cli_validate(int, char **);
	int	*cli_parse(int, char **, int **);

	if ((++argv, --argc == 0)
		|| cli_validate(argc, argv) == false
		|| cli_parse(argc, argv, &nbrs) == NULL)
		return (1);
	argc == 1 && print_nbrs(nbrs, argc);
	argc > 1 && permutate(nbrs, 0, argc);
	free(nbrs);
	return (0);
}