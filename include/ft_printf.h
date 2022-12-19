/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/16 14:35:07 by fras          #+#    #+#                 */
/*   Updated: 2022/12/19 14:08:04 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

typedef int (*Jump_index)(va_list ap);

int		ft_printf(const char *format, ...);
int		index_handler(va_list ap, const char *format);
int		print_conversion(va_list ap, const char *format);
int		pf_putstr(char *s);
int		pf_strlen(const char *s);
int		pf_putchar(char c);

#endif
