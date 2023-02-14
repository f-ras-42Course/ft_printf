/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   num.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/14 16:03:23 by fras          #+#    #+#                 */
/*   Updated: 2023/02/14 19:46:36 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pfhelper_putnbr(va_list ap)
{
	int		num;
	int		len;

	num = va_arg(ap, int);
	len = 0;
	if (num == -2147483648)
		return (write(1, "-2147483648", 11));
	if (num == 0)
		return (write(1, "0", 1));
	if (num < 0)
	{
		len += write(1, "-", 1);
		num *= -1;
	}
	len += helper_numprint(num, &len);
	return (len);
}

int	helper_numprint(int num, int *len)
{
	if (num)
	{
		*len += helper_numprint(num / 10, len);
		return (helper_printer(num % 10 + '0'));
	}
	return (0);
}
