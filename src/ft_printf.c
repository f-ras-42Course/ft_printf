/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/16 14:34:43 by fras          #+#    #+#                 */
/*   Updated: 2022/12/19 13:06:30 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int ret;
	va_list	ap;

	va_start(ap, format);
	ret = index_handler(ap, format);
	va_end(ap);
	return (ret);
}
