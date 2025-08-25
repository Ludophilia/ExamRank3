/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:06:55 by jegerman          #+#    #+#             */
/*   Updated: 2025/08/25 16:07:27 by jegerman         ###   ########.fr       */
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
	char	*dupl;
	int		str_len;
	int		i;

	str_len = ft_strlen(str);
	dupl = malloc((str_len + 1) * sizeof(char));
	if (dupl == NULL)
		return (NULL);
	i = -1;
	while (str[++i])
		dupl[i] = str[i];	
	dupl[i] = 0;
	return (dupl);
}

char	*ft_substr(char *str, unsigned start, unsigned len)
{
	char		*sub;
	unsigned	sub_len;
	unsigned	str_len;
	unsigned	i;

	str_len = ft_strlen(str);
	sub_len = 0;
	while (start + sub_len < str_len && sub_len < len)
		++sub_len;
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	int		len[2];
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
