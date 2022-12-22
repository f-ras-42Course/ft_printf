/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/16 14:35:07 by fras          #+#    #+#                 */
/*   Updated: 2022/12/23 00:20:06 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

typedef int (*t_Jump_index)(va_list);

int		ft_printf(const char *format, ...);
int		index_handler(va_list ap, const char *format);
int		print_conversion(va_list ap, const char index);
int		pf_printer(const char c);
int		pf_strlen(const char *str);
int		pf_putchar(va_list ap);
int		pf_putstr(va_list ap);

#endif
