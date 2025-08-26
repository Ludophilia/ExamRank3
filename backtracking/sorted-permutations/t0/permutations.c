/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 17:55:25 by jegerman          #+#    #+#             */
/*   Updated: 2025/08/26 16:12:44 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

# define SWAP(a, b, T) do { T _t = (a); (a) = (b); (b) = _t; } while (0)

int		ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(char *str)
{
	char	*new;
	int		i;
	
	if ((new = malloc((ft_strlen(str) + 1) * sizeof(char))) == NULL)
		return (NULL);
	i = -1;
	while (str[++i])
		new[i] = str[i];
	new[i] = '\0';
	return (new);
}

int	permutations(int at, char *str, char **sols, int *spos)
{
	if (str[at + 1] == 0)
	{
		sols[*spos] = ft_strdup(str);
		sols[*spos + 1] = 0;
		*spos += 1;
		return (0);
	}
	for (int j = at; str[j]; j++)
	{
		SWAP(str[at], str[j], char);
		permutations(at + 1, str, sols, spos);
		SWAP(str[at], str[j], char);
	}
	return (0);
}

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] && str1[i] == str2[i])
		i++;
	return (str1[i] - str2[i]);
}

int	sort(char **sols)
{
	for (int i = 0; sols[i + 1]; i++)
	{
		for (int j = i; sols[j]; j++)
		{
			if (ft_strcmp(sols[i], sols[j]) > 0)
		 		SWAP(sols[i], sols[j], char *);
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	char	*sols[256];
	int		spos;

	if (++argv, --argc != 1)
		return (1);
	spos = 0;
	permutations(0, *argv, sols, &spos);
	sort(sols);
	for (int i = 0; sols[i]; i++)
	{
		puts(sols[i]);
		free(sols[i]);
	}
	return (0);
}
