/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subsets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:11:30 by jegerman          #+#    #+#             */
/*   Updated: 2025/08/27 19:39:12 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	print_nbrs(int *nbrs, int size)
{
	if (size == 0 && printf("[]\n"))
		return (1);
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

int	build_subset(int from, int *nbr, int size, int *subset, int subsize)
{
	// You could have just stored the array in a bigger one instead of...
	// .. printing the solution right away.
	if (from == size && print_nbrs(subset, subsize))
		return (0);
	// Do not add the number
	build_subset(from + 1, nbr, size, subset, subsize);
	// Add it
	subset[subsize] = nbr[from];
	build_subset(from + 1, nbr, size, subset, subsize + 1);
	subset[subsize] = 0;
	return (0);
}

int	main(int argc, char **argv)
{
	int	*nbrs;
	int	*subset;
	int	*cli_parse(int, char **, int **);

	if ((++argv, --argc == 0)
		|| cli_parse(argc, argv, &nbrs) == NULL)
		return (1);
	if ((subset = malloc(argc * sizeof(int))) == NULL)
		return (free(nbrs), 2);
	build_subset(0, nbrs, argc, subset, 0);
	free(nbrs), free(subset);
	return (0);
}
