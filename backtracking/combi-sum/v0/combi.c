/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:11:30 by jegerman          #+#    #+#             */
/*   Updated: 2025/08/19 19:50:11 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

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

// - Generate duplicates in the candidates set... I don't know how strict they will be...
int	explore(int *nbrs, int at, int nsize, int *sols, int ssize, int target)
{
	if (at == nsize)
	{
		target == 0 && print_nbrs(sols, ssize);
		return (0);
	}
	if (nbrs[at] <= target)
	{
		sols[ssize] = nbrs[at];
		explore(nbrs, at + 1, nsize, sols, ssize + 1, target - nbrs[at]);
		sols[ssize] = 0;
	}
	explore(nbrs, at + 1, nsize, sols, ssize, target);
	return (0);
}

int	main(int argc, char **argv)
{
	int	*nbrs;
	int	*sols;
	int	target;
	int	*cli_parse(int, char **, int **, int *);

	if ((++argv, --argc < 2)
		|| cli_parse(argc, argv, &nbrs, &target) == NULL)
		return (1);
	if ((sols = malloc((argc - 1) * sizeof(int))) == NULL)
		return (free(nbrs), 2);
	explore(nbrs, 0, argc - 1, sols, 0, target);
	free(nbrs), free(sols);
	return (0);
}
