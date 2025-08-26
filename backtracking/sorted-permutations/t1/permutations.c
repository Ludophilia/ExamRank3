/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 17:55:25 by jegerman          #+#    #+#             */
/*   Updated: 2025/08/26 17:47:30 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static void dfs(int level, int n, int cnt[256], char *buf)
{
	if (level == n)
	{
		puts(buf);
		return;
	}
	for (int c = 0; c < 256; ++c)
	{
		if (cnt[c] > 0)
		{
			cnt[c]--;
			buf[level] = (char)c;
			dfs(level + 1, n, cnt, buf);
			cnt[c]++;
		}
    }
}

void	permute_ascii_order(char *comb)
{
    int	comb_len;
    int	cnt[256];
	
	comb_len = strlen(comb);


	for (int i = 0 ; i < 256; i++)
		cnt[i] = 0;

	for (const unsigned char *p = (const unsigned char*)comb; *p; ++p)
		cnt[*p]++;

	char *buf = (char*)malloc(comb_len + 1);
	buf[comb_len] = '\0';
    dfs(0, comb_len, cnt, buf);
	free(buf);
}

int main(int argc, char **argv)
{
	if (++argv, --argc != 1)
		return (1);
    permute_ascii_order(*argv);
    return 0;
}
