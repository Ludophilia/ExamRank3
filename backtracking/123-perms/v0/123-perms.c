/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   123-perms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 12:57:04 by jegerman          #+#    #+#             */
/*   Updated: 2025/08/19 16:51:20 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Generate all permutations of [1, 2, 3] so you can see the “choose → recurse
 → undo” pattern in action. */

// Sure, but how to do this?

// Iterate on every letter until 3 or LIMIT if generalized.

// Start with the first one...
// .. check the condition (must be different from everything that goes before)
// .. if good, go to the next one (new function instance, with different
//    args, usually +1)

// .. check the condition
// .. .. if good, go to the next one,
// .. .. if bad, try the number above,
// .. .. .. if still bad... BACKTRACK (it's just the func instance
//          returning / getting off the stack)

// .. Once you've reached the end, print everything... (HOW)

#include <unistd.h>
#define LIMIT 3

int	print_combs(char *combs)
{
	if (write(1, combs, LIMIT) == -1
		|| write (1, "\n", 1) == -1)
		return (-1);
	return (0);
}

int	never_used_before(int i, char *upto, char *combs)
{
	while (combs != upto)
		if (*combs++ == (i + '0'))
			return (0);
	return (1);
}

int	solve(char *at, char *combs)
{
	for (int i = 1; i <= LIMIT; ++i)
	{
		if (never_used_before(i, at, combs) == 1) // pruning phase
		{
			*at = i + '0'; // choice
			if ((at - combs) == (LIMIT - 1))
				print_combs(combs);
			else
				solve(at + 1, combs); // next step
			*at = '0'; // backtrack
		}
	}
	return (0);
}

int	main(void)
{
	char	*combs;

	combs = (char [LIMIT + 1]){[0 ... LIMIT] = 0};
	solve(combs, combs);
	return (0);
}
