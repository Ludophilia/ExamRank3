/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   123-swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 12:57:04 by jegerman          #+#    #+#             */
/*   Updated: 2025/08/13 19:29:50 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Generate all permutations of [1, 2, 3] so you can see the “choose → recurse
 → undo” pattern in action. */

#include <stdio.h>
#include <unistd.h>
#define LIMIT 3

int	print_comb(int *comb)
{
	char	out[LIMIT];

	for (int i = 0; i < LIMIT; ++i)
		out[i] = comb[i] + '0';
	if (write(1, out, LIMIT) == -1
		|| write(1, "\n", 1) == -1)
		return (-1);
	return (0);
}

void	swap(int *x, int *y)
{
	int	tmp;

	if (x == y)
		return ;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

void	solve(int from, int *comb)
{
	if (from == LIMIT && (print_comb(comb), 1))
		return ;
	for (int i = from; i < LIMIT; i++)
	{
		swap(&comb[from], &comb[i]); // choose
		solve(from + 1, comb); // explore
		swap(&comb[from], &comb[i]); // backtrack, literally undo the swap above
		// HYPER IMPORTANT, else won't go back to the original array once done
		// exploring
	}
}

int main(void)
{
	int	comb[LIMIT];

	for (int i = 0; i < LIMIT; ++i)
		comb[i] = i + 1; // starts from 123
	solve(0, comb);
}
