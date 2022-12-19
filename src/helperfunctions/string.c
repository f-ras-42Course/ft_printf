/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   string.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/18 11:58:07 by fras          #+#    #+#                 */
/*   Updated: 2022/12/19 11:07:33 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_putstr(char *s)
{
	write(1, s, ft_strlen(s));
	return(pf_strlen);
}

int	pf_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
