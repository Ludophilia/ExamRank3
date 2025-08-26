/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 17:55:25 by jegerman          #+#    #+#             */
/*   Updated: 2025/08/26 19:12:23 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		++len;
	return (len);
}

static void permutations(int at, char *comb, int len, int cfreq[256])
{
	if (at == len && puts(comb))
		return;
	for (int c = 0; c < 256; c++)
	{
		if (cfreq[c] > 0)
		{
			cfreq[c]--;
			comb[at] = c;
			permutations(at + 1, comb, len, cfreq);
			cfreq[c]++;
		}
	}
}

int main(int argc, char **argv)
{
	int	cfrq[256] = {0}; // The histogram.

	if (++argv, --argc != 1)
		return (1);
	for (unsigned char *p = (unsigned char*)*argv; *p; p++)
		cfrq[*p]++;
	permutations(0, *argv, ft_strlen(*argv), cfrq);
	return (0);
}
