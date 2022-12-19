/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handler.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/16 20:09:43 by fras          #+#    #+#                 */
/*   Updated: 2022/12/19 12:37:04 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	index_handler(va_list ap, const char *format)
{
	int	ret;

	ret = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
				break;
			ret += print_conversion(ap, format);
			format++;
		}
		else
		{
			ret += pf_putchar(*format);
			format++;
		}
	}
	return (ret);
}

int		print_conversion(va_list ap, const char *format)
{
	int ret;

	ret = 0;
	Jump_index	convert[] = {
	['c'] = &pf_putchar,
	['s'] = &pf_putstr
	}

	return(convert[format](ap));
}
