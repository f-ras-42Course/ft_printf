/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   errors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/23 00:40:47 by fras          #+#    #+#                 */
/*   Updated: 2023/02/14 18:01:01 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

void	error(void)
{
	write(2, _RED "ft_printf error: ", 24);
}

int	error_invalid_conversion(char conversion)
{
	error();
	write(2, _WHITE "invalid conversion specifier.. '", 39);
	write(2, &conversion, 1);
	write(2, "'" _RESET, 5);
	return (-1);
}
