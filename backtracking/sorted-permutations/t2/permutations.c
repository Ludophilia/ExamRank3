/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 17:55:25 by jegerman          #+#    #+#             */
/*   Updated: 2025/08/27 19:41:06 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	permutations(int at, char *comb, int len, int cfreq[256])
{
	if (at == len && puts(comb))
		return (0);
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
	return (0);
}

int main(int argc, char **argv)
{
	static int	cfreq[256];

	if (++argv, --argc != 1)
		return (1);
	for (unsigned char *c = (unsigned char *)*argv; *c; c++)
		cfreq[*c]++;
	permutations(0, *argv, ft_strlen(*argv), cfreq);
	return (0);
}
