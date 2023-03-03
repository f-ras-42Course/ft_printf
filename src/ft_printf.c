/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/16 14:34:43 by fras          #+#    #+#                 */
/*   Updated: 2023/03/03 20:49:29 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		print_length;
	va_list	ap;

	va_start(ap, format);
	print_length = format_handler(ap, format);
	va_end(ap);
	return (print_length);
}

int	format_handler(va_list ap, const char *format)
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
			if (!conversions(*format))
				return (error_invalid_conversion(*format));
			print_length += print_conversion(ap, *format);
			format++;
		}
		else
		{
			print:
			print_length += helper_printer(*format);
			format++;
		}
	}
	return (print_length);
}

int	conversions(char conversion)
{
	return (conversion == 'c' || conversion == 's' || conversion == 'd'
		|| conversion == 'i' || conversion == 'u' || conversion == 'x'
		|| conversion == 'X' || conversion == 'p');
}

int	print_conversion(va_list ap, const char index)
{
	static const t_Jump_index	convert[] = {
	['c'] = &pfhelper_putchar,
	['s'] = &pfhelper_putstr,
	['i'] = &pfhelper_putnbr,
	['d'] = &pfhelper_putnbr,
	['u'] = &pfhelper_putnbr_unsigned,
	['x'] = &pfhelper_puthex_lowercase,
	['X'] = &pfhelper_puthex_uppercase,
	['p'] = &pfhelper_putpointeraddress,
	};

	return (convert[(unsigned int)index](ap));
}
