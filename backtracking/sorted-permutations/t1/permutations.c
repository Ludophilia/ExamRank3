/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 17:55:25 by jegerman          #+#    #+#             */
/*   Updated: 2025/08/26 17:26:26 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static void dfs(int level, int n, int cnt[256], char *buf) {
    if (level == n)
	{
        puts(buf);
        return;
    }
    for (int c = 0; c < 256; ++c){          // ASCII order
        if (cnt[c] > 0) {
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
	// char *buffer;

	comb_len = strlen(comb);
	cnt[0] = 0;

	for (unsigned char *p = comb; *p; ++p)
		cnt[*p]++;


	
	// buffer = malloc(comb_len + 1);
    // buffer[comb_len] = '\0';
    dfs(0, comb_len, cnt, comb);
    // free(buffer);
}

int main(int argc, char **argv)
{
	if (++argv, --argc != 1)
		return (1);
    permute_ascii_order(*argv);
    return 0;
}
