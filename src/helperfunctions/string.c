/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   string.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/18 11:58:07 by fras          #+#    #+#                 */
/*   Updated: 2022/12/22 23:56:50 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_putstr(t_type_selections *vars)
{
	vars->str = va_arg(vars->data, char *);
	write(1, vars->str, pf_strlen(vars->str));
	return(pf_strlen(vars->str));
}

int	pf_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
