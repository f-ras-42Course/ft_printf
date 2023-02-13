/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/16 14:34:43 by fras          #+#    #+#                 */
/*   Updated: 2023/02/13 17:18:46 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int print_length;
	va_list	ap;

	va_start(ap, format);
	print_length = format_handler(ap, format);
	va_end(ap);
	return (print_length);
}
