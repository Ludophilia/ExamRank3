/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 17:10:22 by jegerman          #+#    #+#             */
/*   Updated: 2025/06/08 15:31:14 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		++len;
	return (len);
}

char	*ft_strdup(char *str)
{
	char	*dup;
	int		str_len;
	int		i;
	
	str_len = ft_strlen(str);
	dup = malloc((str_len + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	i = -1;
	while (str[++i])
		dup[i] = str[i];
	dup[i] = 0;
	return (dup);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len[2];
	char	*join;
	int		i;
	
	len[0] = ft_strlen(s1);
	len[1] = ft_strlen(s2);
	join = malloc((len[0] + len[1] + 1) * sizeof(char));
	if (join == NULL)
		return (NULL);
	i = -1;
	while (s1[++i])
		join[i] = s1[i];
	--i;
	while (s2[++i - len[0]])
		join[i] = s2[i - len[0]];
	join[i] = 0;
	return (join);
}

char	*ft_substr(char *str, unsigned start, unsigned len)
{
	unsigned	str_len;
	char		*sub;
	unsigned	sub_len;
	unsigned	i;

	str_len = ft_strlen(str);
	sub_len = 0;
	while ((start + sub_len) < str_len && sub_len < len)
		sub_len++;
	sub = malloc((sub_len + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (i < sub_len)
	{
		sub[i] = str[start + i];
		++i;
	}
	sub[i] = 0;
	return (sub);
}

