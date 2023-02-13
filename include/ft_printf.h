/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/16 14:35:07 by fras          #+#    #+#                 */
/*   Updated: 2023/02/13 17:23:31 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

#define _RED		"\e[1;31m"
#define _WHITE		"\e[1;37m"
#define _RESET		"\e[0m"

typedef int (*t_Jump_index)(va_list);

int		ft_printf(const char *format, ...);
int		format_handler(va_list ap, const char *format);
int		print_conversion(va_list ap, const char index);
int		printer(const char c);
int		strlen(const char *str);
int		putchar(va_list ap);
int		putstr(va_list ap);
int		conversions(char conversion);
void	error(void);
int		error_invalid_conversion(char conversion);

#endif
