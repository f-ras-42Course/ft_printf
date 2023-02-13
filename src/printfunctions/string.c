/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   string.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/18 11:58:07 by fras          #+#    #+#                 */
/*   Updated: 2023/02/13 17:23:25 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putstr(va_list ap)
{
	char *str;

	str = va_arg(ap, char *);
	write(1, str, pf_strlen(str));
	return(pf_strlen(str));
}

int	strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
