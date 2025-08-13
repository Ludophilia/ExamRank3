/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:44:01 by jegerman          #+#    #+#             */
/*   Updated: 2025/06/07 18:39:33 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *str)
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
	int		len;
	int		i;

	len = ft_strlen(str);
	dupl = malloc((len + 1) * sizeof(char));
	if (dupl == NULL)
		return (NULL);
	i = -1;
	while (str[++i])
		dupl[i] = str[i];
	dupl[i] = 0;
	return (dupl);
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
	i = -1; // Err, i = 0;
	while (s1[++i])
		join[i] = s1[i];
	i--;
	while (s2[++i - len[0]])
		join[i] = s2[i - len[0]];
	join[i] = 0;
	return (join);
}

char	*ft_substr(char *str, unsigned int start, unsigned int len)
{
	unsigned int	sub_len;
	unsigned int	str_len;
	char			*sub;
	unsigned int	i;

	sub_len = 0;
	str_len = ft_strlen(str);
	while ((start + sub_len) < str_len && sub_len < len)
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
