/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ten-queens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 13:37:23 by jegerman          #+#    #+#             */
/*   Updated: 2025/08/15 18:05:08 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
# 025 794 8136. What are those already?
- The row pos in each col, from col 0 to col 9.

# What are the conditions to respect for a queen placement to be valid?

	- Not a queen in...
		- the same row (check before)
		- the same col (check before)
			- Never happens, as we make a distinct new row choice for 
		- the same diag (right up to left down)
			- the sum (row + col) stays the same
		- the same diag (left up to right down)
			- the difference (row - col) stays the same

			 (C)
			  0 1 2 3 4
		(R) 0 . . . . .
		    1 . . . . .
		    2 . . . . .
		    3 . . . . .
		    4 . . . . .

*/

#include <unistd.h>
#include <stdio.h>

static int	print_comb(char *comb, int *count)
{
	if (write(1, comb, 10) == -1
		|| write(1, "\n", 1) == -1)
		return (-1);
	*count += 1;
	return (1);
}

/*
	2) O(1) checks with 3 occupancy arrays

	Instead of scanning previous columns each time, keep three boolean arrays:
	row_used[row]
	diag1_used[row + col] // “\” diagonals
	diag2_used[row - col + (N-1)] // “/” diagonals
	This makes validity checks O(1) and gives a big speedup.
*/
static int	check_pos_validity(int row, int col, char *comb)
{
	int	icol;
	int	irow;

	icol = -1;
	while (++icol < col)
	{
		irow = comb[icol] - '0';
		if (irow == row
			|| (irow + icol) == (row + col)
			|| (irow - icol) == (row - col))
			return (0);
	}
	return (1);
}

/* 4) Easy symmetry cut (2× speed)

If you keep your column‑by‑column approach, you can reduce search by symmetry:
in the first column, only try rows 0..(N/2 - 1) and double the solutions 
you find by mirroring—just be careful to handle the exact printing 
(you can either actually mirror‑print or just count
and print only the “half” set). */

static int	solve_for_col(int col, char *comb, int *count)
{
	int		row;

	if (col == 10 && print_comb(comb, count))
		return (0);
	row = -1;
	while (++row < 10)
	{
		if (check_pos_validity(row, col, comb))
		{
			comb[col] = row + '0';
			solve_for_col(col + 1, comb, count);
			comb[col] = '0';
		}
	}
	return (0);
}

int	ft_ten_queens_puzzle(void)
{
	int		count;
	char	comb[11];

	for (int i = 0; i < 10; i++)
		comb[i] = '0';
	comb[10] = 0;
	count = 0;
	solve_for_col(0, comb, &count);
	return (count);
}

int	main(void)
{
	printf("(solutions -> %i)\n", ft_ten_queens_puzzle());
	return (0);
}
