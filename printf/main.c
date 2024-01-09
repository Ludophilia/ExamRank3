/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:49:03 by jgermany          #+#    #+#             */
/*   Updated: 2024/01/09 18:43:54 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

int	main(void)
{	
	printf("ft: %i\n", ft_printf("NULL\n"));
	printf("ori: %i\n", printf("NULL\n"));
}
