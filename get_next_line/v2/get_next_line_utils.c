/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:44:01 by jegerman          #+#    #+#             */
/*   Updated: 2025/05/30 17:22:36 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	*ft_substr(char *s, unsigned int start, unsigned int len)
// {
// 	char			*sub;
// 	unsigned int	s_len;
// 	unsigned int	sub_len;
// 	unsigned int	i;

// 	if (s == NULL)
// 		return (NULL);
// 	s_len = ft_strlen(s);
// 	sub_len = 0;
// 	while (start + sub_len < s_len && sub_len < len)
// 		++sub_len;
// 	sub = malloc((sub_len + 1) * sizeof(char));
// 	if (sub == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (i < sub_len)
// 	{
// 		sub[i] = s[start + i];
// 		++i;
// 	}
// 	sub[i] = 0;
// 	return (sub);
// }

// int		ft_strlen(char *s)
// {
// 	int	len;
	
// 	len = 0;
// 	while (s[len])
// 		++len;
// 	return (len);
// }

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	int		len[2];
// 	char	*s1s2;
// 	int		i;

// 	len[0] = ft_strlen(s1);
// 	len[1] = ft_strlen(s2);
// 	s1s2 = malloc((len[0] + len[1] + 1) * sizeof(char));
// 	if (s1s2 == NULL)
// 		return (NULL);
// 	i = -1;
// 	while (s1[++i])
// 		s1s2[i] = s1[i];
// 	--i;
// 	while (s2[++i - len[0]])
// 		s1s2[i] = s2[i - len[0]];
// 	s1s2[i] = 0;
// 	return (s1s2);
// }

// char	*ft_strdup(char *s)
// {
// 	char	*dpl;
// 	int		s_len;
// 	int		i;

// 	s_len = ft_strlen(s);
// 	dpl = malloc((s_len + 1) * sizeof(char));
// 	if (dpl == NULL)
// 		return (NULL);
// 	i = -1;
// 	while (s[++i])
// 		dpl[i] = s[i];
// 	dpl[i] = 0;
// 	return (dpl);		
// }

// char	*ft_substr(char *s, unsigned int start, unsigned int len)
// {
// 	char			*sub;
// 	unsigned int	s_len;
// 	unsigned int	;

	
// }
