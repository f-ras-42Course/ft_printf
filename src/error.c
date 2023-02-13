/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/23 00:40:47 by fras          #+#    #+#                 */
/*   Updated: 2023/02/13 16:38:49 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	error(char conversion)
{
	char *message[1];
	write(2, _RED "error:", 14);
	message[0] = _WHITE " invalid conversion specifier.. '";
	write(2, message[0], 40);
	write(2, _RESET "", 5);
	write(2, &conversion, 1);
	write(2, "'", 2);
	return(-1);
}