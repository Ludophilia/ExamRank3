/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abc-perms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 12:57:04 by jegerman          #+#    #+#             */
/*   Updated: 2025/08/27 18:56:35 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	is_not_duplicate(int cand, char *combs, int at)
{
	for (int j = 0; j < at; j++)
		if (combs[j] == cand)
			return (0);
	return (1);
}

int	solve(int at, char *combs, int len)
{
	if ((at == len) && puts(combs))
		return (0);
	for (int i = 0; i < len; i++)
	{
		if (is_not_duplicate(i + 'a', combs, at))
		{
			combs[at] = i + 'a';
			solve(at + 1, combs, len);
			combs[at] = 0;
		}
	}
	return (0);
}

/* That method suggest contiguity between the different elements. Can't
be used therefore for swaping alphabetically a discrete set of elements */
int	main(int argc, char **argv)
{
	static char	combs[256];

	if (++argv, --argc != 1)
		return (1);
	solve(0, combs, atoi(*argv));
	return (0);
}
