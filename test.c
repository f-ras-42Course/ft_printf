/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/19 10:22:41 by fras          #+#    #+#                 */
/*   Updated: 2023/02/14 13:48:41 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char	*str;
	char	c;

	str = "string";
	c = 'c';
	printf("ret = %d \n", ft_printf("Hello"));
	printf("ret = %d \n", ft_printf("hello %s", str));
	printf("ret = %d \n", ft_printf("hello %c", c));
	printf("ret = %d \n", ft_printf("hello %M", c));
	printf("\n\n\n");
	printf("ret = %d", printf("Hello\n"));
	printf("ret = %d", printf("hello %s\n", str));
	printf("ret = %d", printf("hello %c\n", c));
	// printf("ret = %d \n", printf("hello %M", c));
	return (0);
}
