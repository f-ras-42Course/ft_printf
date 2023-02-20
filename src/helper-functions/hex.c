/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hex.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/14 15:05:25 by fras          #+#    #+#                 */
/*   Updated: 2023/02/20 16:07:33 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int	pfhelper_putpointeraddress(va_list ap)
// {
// 	void	*ptr;
// 	int		len;

// 	ptr = va_arg(ap, void *);
// 	len = 0;
// 	len += helper_dec_to_hexconverter(&ptr, &len);
// 	return(len);
// }

int pfhelper_puthex(va_list ap)
{
	int dec;
	int len;

	dec = va_arg(ap, int);
	len = 0;
	len += helper_dec_to_hexconverter(dec, &len);
	return (len);
}

int	helper_dec_to_hexconverter(unsigned int dec, int *len)
{
	if (dec >= 0 && dec < 16)
	{
		if (dec <= 9)
			return (helper_printer(dec + '0'));
		else
			return (helper_printer(dec % 10 + 'a'));
	}
	if (dec >= 16)
	{
		*len += helper_dec_to_hexconverter(dec / 16, len);
		if ((dec % 16) > 9 && (dec % 16) < 16)
			return (helper_printer((dec % 16) % 10 + 'a'));
		else
			return (helper_printer((dec % 16) + '0'));
	}
	return (0);
}
