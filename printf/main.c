/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:49:03 by jgermany          #+#    #+#             */
/*   Updated: 2024/01/10 15:02:05 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

#define THE_MESSAGE "The Nintendo RVL-001 was released in Nov. 06 in EU, the US, and JP."

void	the_verdict(void)
{
	printf("ft: %i\n", ft_printf(NULL));
	printf("ori: %i\n", printf(NULL));
	printf("####################################################\n");	
	printf("ft: %i\n", ft_printf("Hi\n"));
	printf("ori: %i\n", printf("Hi\n"));
	printf("####################################################\n");
	printf("ft: %i\n", ft_printf("`%s`\n", 0));
	printf("ori: %i\n", printf("`%s`\n", 0));
	printf("####################################################\n");
	printf("ft: %i\n", ft_printf("The message: `%s`\n", THE_MESSAGE));
	printf("ori: %i\n", printf("The message: `%s`\n", THE_MESSAGE));
	printf("####################################################\n");
	printf("ft: %d\n", ft_printf("%d\n", -2147483649));
	printf("ori: %d\n", printf("%d\n", -2147483649));
	printf("####################################################\n");
	printf("ft: %d\n", ft_printf("%d\n", -2147483646));
	printf("ori: %d\n", printf("%d\n", -2147483646));
	printf("####################################################\n");
	printf("ft: %d\n", ft_printf("%d\n", -10));
	printf("ori: %d\n", printf("%d\n", -10));
	printf("####################################################\n");
	printf("ft: %d\n", ft_printf("%d\n", 0));
	printf("ori: %d\n", printf("%d\n", 0));
	printf("####################################################\n");
	printf("ft: %d\n", ft_printf("%d\n", 10));
	printf("ori: %d\n", printf("%d\n", 10));
	printf("####################################################\n");
	printf("ft: %d\n", ft_printf("%d\n", 2147483648));
	printf("ori: %d\n", printf("%d\n", 2147483648));
	printf("####################################################\n");
	printf("ft: %d\n", ft_printf("%x\n", -1));
	printf("ori: %d\n", printf("%x\n", -1));
	printf("####################################################\n");
	printf("ft: %d\n", ft_printf("%x\n", 0x0));
	printf("ori: %d\n", printf("%x\n", 0x0));
	printf("####################################################\n");
	printf("ft: %d\n", ft_printf("%x\n", 0x2A));
	printf("ori: %d\n", printf("%x\n", 0x2A));
	printf("####################################################\n");
	printf("ft: %d\n", ft_printf("%x\n", 0xFFFFFFFF));
	printf("ori: %d\n", printf("%x\n", 0xFFFFFFFF));
	printf("####################################################\n");
	printf("ft: %d\n", ft_printf("%x\n", (1 << 32)));
	printf("ori: %d\n", printf("%x\n", (1 << 32)));
	printf("####################################################\n");
	printf("ft: %d\n", ft_printf("%x%d%s\n", 0xFFFFFFFF, -42, "printf style"));
	printf("ori: %d\n", printf("%x%d%s\n", 0xFFFFFFFF, -42, "printf style"));
	printf("####################################################\n");
	printf("ft: %d\n", ft_printf("(%d/%x)%s     %s   . %s!\n",
		0xA, 10, "maman,", "j'ai faim", "WOOOLA"));
	printf("ft: %d\n", printf("(%d/%x)%s     %s   . %s!\n",
		0xA, 10, "maman,", "j'ai faim", "WOOOLA"));
}

int	main(void)
{
	the_verdict();
	return (0);
}
