/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rip.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 18:07:05 by jegerman          #+#    #+#             */
/*   Updated: 2025/08/16 18:39:04 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	rip(char *str) // rpar_rc // lpar_rc // open
{


}

// len 0 str
// already balanced

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		++len;
	return (len); 
}

int	check_balance(char *str, int *rp_rm, int *lp_rm)
{
	int	i;
	int	len;

	*rp_rm = 0;
	*lp_rm = 0;
	len = ft_strlen(str);
	if (len == 0)
		return (0);
	// len 1 already balance ? 
	//		'(' or ')'; remove one and should be done.
	i = -1;
	
}

int	main(int argc, char **argv)
{
	if (*(++argv) == NULL && --argc != 1)
		return (1);
	// check what's needed to balance the parentheses
	rip(*argv);
	return (0);
}
