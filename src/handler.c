/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handler.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/16 20:09:43 by fras          #+#    #+#                 */
/*   Updated: 2022/12/23 00:31:01 by fras          ########   odam.nl         */
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
			if (*format == '\0')
				break;
			if (*format == '%')
				goto print;
			ret += print_conversion(ap, *format);
			format++;
		}
		else
		{
			print:
			ret += pf_printer(*format);
			format++;
		}
	}
	return (ret);
}

int		print_conversion(va_list ap, const char index)
{
	t_Jump_index	convert[] = {
	['c'] = &pf_putchar,
	['s'] = &pf_putstr,
	};
	
	return(convert[(unsigned int)index](ap));
}
