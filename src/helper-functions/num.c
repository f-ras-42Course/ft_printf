/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   num.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/14 16:03:23 by fras          #+#    #+#                 */
/*   Updated: 2023/02/15 12:38:34 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pfhelper_putnbr(va_list ap)
{
	int		num;
	int		len;

	num = va_arg(ap, int);
	len = 0;
	len += helper_numprint(num, &len);
	return (len);
}

int	helper_numprint(int num, int *len)
{
	if (num >= 0 && num <= 9)
		return (helper_printer(num + '0'));
	if (num >= 10)
	{
		*len += helper_numprint(num / 10, len);
		return (helper_printer(num % 10 + '0'));
	}
	if (num < 0)
	{
		if (num == -2147483648)
			return (write(1, "-2147483648", 11));
		else
		{
			*len += helper_printer('-');
			return (helper_numprint(num * -1, len));
		}
	}
	return (0);
}
