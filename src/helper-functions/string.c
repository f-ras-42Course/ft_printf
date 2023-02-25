/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   string.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/18 11:58:07 by fras          #+#    #+#                 */
/*   Updated: 2023/02/15 14:45:49 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pfhelper_putstr(va_list ap)
{
	char	*str;

	str = va_arg(ap, char *);
	if (!str)
		return(write(1, "(null)", 6));
	write(1, str, helper_strlen(str));
	return (helper_strlen(str));
}

int	helper_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
