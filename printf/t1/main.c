/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:16:16 by jgermany          #+#    #+#             */
/*   Updated: 2024/01/15 19:06:01 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

#define THE_MESSAGE_PT1 "The X360 was the second game console designed by "
#define THE_MESSAGE_PT2 "Microsoft, the Redmond based software giant."

int	main(void)
{
	printf("ft -> %i\n", ft_printf(""));
	printf("og -> %i\n", printf(""));
	printf("ft -> %i\n", ft_printf("J"));
	printf("og -> %i\n", printf("J"));
	printf("ft -> %i\n", ft_printf("Hello"));
	printf("og -> %i\n", printf("Hello"));
	printf("ft -> %i\n", ft_printf("                  0"));
	printf("og -> %i\n", printf("                  0"));
	printf("ft -> %i\n", ft_printf(NULL));
	// printf("og -> %i\n", printf(NULL));
	printf("###############################################################\n");

	// printf("ft -> %i\n", ft_printf("% "));
	// printf("og -> %i\n", printf("% "));
	// printf("ft -> %i\n", ft_printf("%w"));
	// printf("og -> %i\n", printf("%w"));
	// printf("ft -> %i\n", ft_printf("%wassas"));
	// printf("og -> %i\n", printf("%wassas"));
	// printf("ft -> %i\n", ft_printf("%w assas"));
	// printf("og -> %i\n", printf("%w assas"));
	// printf("###############################################################\n");

	printf("ft -> %i\n", ft_printf("%s\n", NULL));
	printf("og -> %i\n", printf("%s\n", NULL));
	printf("ft -> %i\n", ft_printf("%s\n", ""));
	printf("og -> %i\n", printf("%s\n", ""));
	printf("ft -> %i\n", ft_printf("%s\n", "hello"));
	printf("og -> %i\n", printf("%s\n", "hello"));
	printf("ft -> %i\n", ft_printf("The message: `%s`\n",
		THE_MESSAGE_PT1 THE_MESSAGE_PT2));
	printf("og -> %i\n", printf("The message: `%s`\n",
		THE_MESSAGE_PT1 THE_MESSAGE_PT2));
	printf("###############################################################\n");

	printf("ft -> %i\n", ft_printf("%d\n", -2147483650));
	printf("og -> %i\n", printf("%d\n", -2147483650));
	printf("ft -> %i\n", ft_printf("%d\n", -2147483648));
	printf("og -> %i\n", printf("%d\n", -2147483648));
	printf("ft -> %i\n", ft_printf("%d\n", -10));
	printf("og -> %i\n", printf("%d\n", -10));
	printf("ft -> %i\n", ft_printf("%d\n", 0));
	printf("og -> %i\n", printf("%d\n", 0));
	printf("ft -> %i\n", ft_printf("%d\n", 10));
	printf("og -> %i\n", printf("%d\n", 10));
	printf("ft -> %i\n", ft_printf("%d\n", 42));
	printf("og -> %i\n", printf("%d\n", 42));
	printf("ft -> %i\n", ft_printf("%d\n", 2147483647));
	printf("og -> %i\n", printf("%d\n", 2147483647));
	printf("ft -> %i\n", ft_printf("%d\n", 2147483648));
	printf("og -> %i\n", printf("%d\n", 2147483648));
	printf("###############################################################\n");

	printf("ft -> %i\n", ft_printf("%x\n", -1));
	printf("og -> %i\n", printf("%x\n", -1));
	printf("ft -> %i\n", ft_printf("%x\n", 0));
	printf("og -> %i\n", printf("%x\n", 0));
	printf("ft -> %i\n", ft_printf("%x\n", 0x2A));
	printf("og -> %i\n", printf("%x\n", 0x2A));
	printf("ft -> %i\n", ft_printf("%x\n", 0xFF));
	printf("og -> %i\n", printf("%x\n", 0xFF));
	printf("ft -> %i\n", ft_printf("%x\n", 2147483648));
	printf("og -> %i\n", printf("%x\n", 2147483648));
	printf("ft -> %i\n", ft_printf("%x\n", 0xFFFFFFFF));
	printf("og -> %i\n", printf("%x\n", 0xFFFFFFFF));
	printf("ft -> %i\n", ft_printf("%x\n", 0xFFFFFFFF + 1));
	printf("og -> %i\n", printf("%x\n", 0xFFFFFFFF + 1));
	printf("###############################################################\n");

	printf("ft -> %i\n", ft_printf("[%x]%d, %s%d%s%x%s!\n",
		getpid(), 0x2A, "c'est", 2, "la", 0x8, "onne"));
	printf("ft -> %i\n", printf("[%x]%d, %s%d%s%x%s!\n",
		getpid(), 0x2A, "c'est", 2, "la", 0x8, "onne"));
	printf("###############################################################\n");
	return (0);
}
