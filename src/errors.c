/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   errors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/23 00:40:47 by fras          #+#    #+#                 */
/*   Updated: 2023/02/25 18:53:53 by fras          ########   odam.nl         */
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
	if (conversion == '\0')
		return (error_incomplete_format());
	error();
	write(2, _WHITE "invalid conversion specifier '", 37);
	write(2, &conversion, 1);
	write(2, "'" _RESET, 5);
	return (-1);
}

int	error_incomplete_format(void)
{
	error();
	write(2, _WHITE "incomplete format specifier", 36);
	write(2, _RESET, 4);
	return (-1);
}
