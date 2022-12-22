/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/19 10:22:41 by fras          #+#    #+#                 */
/*   Updated: 2022/12/23 00:33:17 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
int	main(void)
{
	char *str = "string";
	char c = 'c';

	ft_printf("Hello\n");
	ft_printf("hello %s\n", str);
	ft_printf("hello %c\n", c);
	ft_printf("hello %%%", c);
	// printf("hello %%%", c);
	return (0);
}
