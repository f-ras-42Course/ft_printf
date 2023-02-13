/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   char.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/16 19:16:13 by fras          #+#    #+#                 */
/*   Updated: 2023/02/13 17:23:17 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printer(const char c)
{
	write(1, &c, 1);
	return (1);
}

int	putchar(va_list ap)
{
	char c;

	c = va_arg(ap, int);
	write(1, &c, 1);
	return (1);
}
