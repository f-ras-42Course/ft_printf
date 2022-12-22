/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/16 14:35:07 by fras          #+#    #+#                 */
/*   Updated: 2022/12/22 23:55:42 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

typedef struct s_type_selections
{
	va_list data;
	char 	chr;
	const char 	*str;
}	t_type_selections;

typedef int (*t_Jump_index)(t_type_selections *);


int		ft_printf(const char *format, ...);
int		index_handler(va_list ap, const char *format);
int		print_conversion(va_list ap, const char index);
int		pf_putstr(t_type_selections *vars);
int		pf_strlen(const char *str);
int		pf_putchar(const char c);
int		pf_putchar2(t_type_selections *vars);
int		pf_putpercent(t_type_selections *vars);

#endif
