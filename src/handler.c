/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handler.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/16 20:09:43 by fras          #+#    #+#                 */
/*   Updated: 2022/12/23 01:28:51 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	index_handler(va_list ap, const char *format)
{
	int	print_length;

	print_length = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
				goto print;
			if (*format != 'c' && *format != 's')
				return(error());
			print_length += print_conversion(ap, *format);
			format++;
		}
		else
		{
			print:
			print_length += pf_printer(*format);
			format++;
		}
	}
	return (print_length);
}

int		print_conversion(va_list ap, const char index)
{
	t_Jump_index	convert[] = {
	['c'] = &pf_putchar,
	['s'] = &pf_putstr,
	};
	
	return(convert[(unsigned int)index](ap));
}
