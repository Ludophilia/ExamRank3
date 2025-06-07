/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:53:51 by jgermany          #+#    #+#             */
/*   Updated: 2024/01/15 19:24:07 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	my_strlen(char *str)
{
	int	len;

	if (str == NULL)
		return (-1);
	len = -1;
	while (str[++len])
		;
	return (len);
}

int	my_strchr(int c, char *str)
{
	int	i;

	if (str == NULL)
		return (-1);
	i = -1;
	while (str[++i])
		if (str[i] == c)
			return (i);
	return (-1);
}

char	*my_strdup(char *str)
{
	char	*dup_str;
	int		og_len;
	int		i;

	if (str == NULL)
		return (NULL);
	og_len = my_strlen(str);
	dup_str = malloc((og_len + 1) * sizeof(char));
	if (dup_str == NULL)
		return (NULL);
	i = -1;
	while (++i < og_len + 1)
		dup_str[i] = 0;
	i = -1;
	while (str[++i])
		dup_str[i] = str[i];
	return (dup_str);
}

char	*my_strjoin(char *str1, char *str2)
{
	char	*join_str;
	int		lens[2];
	int		ij[2];

	if (str1 == NULL || str2 == NULL)
		return (NULL);
	lens[0] = my_strlen(str1);
	lens[1] = my_strlen(str2);
	join_str = malloc((lens[0] + lens[1] + 1) * sizeof(char));
	if (join_str == NULL)
		return (NULL);
	ij[0] = -1;
	while (++ij[0] < lens[0] + lens[1] + 1)
		join_str[ij[0]] = 0;
	*(long *)ij = 0;
	while (str1[ij[1]])
		join_str[ij[0]++] = str1[ij[1]++];
	ij[1] = 0;
	while (str2[ij[1]])
		join_str[ij[0]++] = str2[ij[1]++];
	return (join_str);
}

char	*my_substr(char *str, int start, int len)
{
	char	*sub_str;
	int		i;

	if (str == NULL || start < 0 || len < 1 || start > (my_strlen(str) - 1)
		|| len > (my_strlen(str) - start))
		return (NULL);
	sub_str = malloc((len + 1) * sizeof(char));
	if (sub_str == NULL)
		return (NULL);
	i = -1;
	while (++i < len + 1)
		sub_str[i] = 0;
	i = -1;
	while (++i < len)
		sub_str[i] = str[start + i];
	return (sub_str);
}
