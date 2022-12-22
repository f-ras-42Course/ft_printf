/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   char.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/16 19:16:13 by fras          #+#    #+#                 */
/*   Updated: 2022/12/22 23:52:52 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_putchar(const char c)
{
	write(1, &c, 1);
	return (1);
}

int	pf_putchar2(t_type_selections *vars)
{
	vars->chr = va_arg(vars->data, int);
	write(1, &vars->chr, 1);
	return (1);
}
