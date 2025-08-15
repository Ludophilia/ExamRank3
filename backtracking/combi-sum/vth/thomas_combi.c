/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thos_combi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 08:43:16 by thodavid          #+#    #+#             */
/*   Updated: 2025/08/15 19:33:12 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

/*------------------------------------------------------------*/
/*  backtracking                                              */
/*------------------------------------------------------------*/
/* arr      : tableau des valeurs                             */
/* subset   : tableau chemin courant                          */
/* len      : taille de arr                                   */
/* sub_len  : profondeur courante (= nb d’éléments du subset) */
/* idx      : index de départ pour la boucle                  */
/* sum      : somme courante                                  */
/* target   : somme recherchée                                */

static void	backtrack(int *arr, int *subset,
		int len, int sub_len,
		int idx, int sum, int target)
{
	if (sum == target) /* feuille valide */
	{
		int k = 0;
		while (k < sub_len)
		{
			printf("%d", subset[k]);
			if (k + 1 < sub_len)
				printf(" ");
			k++;
		}
		putchar('\n');
		return;
	}
	if (idx == len)                           
		return;

	while (idx < len)
	{
		int val = arr[idx];

		subset[sub_len] = val;
		backtrack(arr, subset, len, sub_len + 1,
				idx + 1, sum + val, target);

		idx++;                                 
	}
}


int	main(int ac, char **av)
{
	if (ac < 3) 
		return (0);

	int target = atoi(av[1]);
	int len    = ac - 2;

	/* allocation tableau des nombres */
	int *arr = malloc(len * sizeof(int));
	int *subset = malloc(len * sizeof(int));
	if (!arr || !subset)
	{
		free(arr);
		free(subset);
		return (1);                            
	}

	int i = 0;
	while (i < len)
	{
		arr[i] = atoi(av[i + 2]);
		i++;
	}

	backtrack(arr, subset, len, 0, 0, 0, target);

	free(arr);
	free(subset);
	return (0);
}