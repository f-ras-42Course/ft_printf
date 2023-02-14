/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/19 10:22:41 by fras          #+#    #+#                 */
/*   Updated: 2023/02/14 19:14:42 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void tester (int ft_ret, int org_ret, int testcase);

int	main(void)
{
	char	*str;
	char	c;
	int		num1;
	int		num2;
	int		num3;
	int		num4;
	int		test;

	str = "string";
	c = 'c';
	num1 = 0;
	num2 = 12346;
	num3 = -12346;
	num4 = -2147483648;
	test = 1;
	ft_printf("Hello");
	printf(" | [%d] ft_ret = %d \n", test++, ft_printf("hello %s", str));
	printf(" | [%d] ft_ret = %d \n", test++, ft_printf("hello %c", c));
	printf(" | [%d] ft_ret = %d \n", test++, ft_printf("hello %d", num1));
	printf(" | [%d] ft_ret = %d \n", test++, ft_printf("hello %d", num2));
	printf(" | [%d] ft_ret = %d \n", test++, ft_printf("hello %d", num3));
	printf(" | [%d] ft_ret = %d \n", test++, ft_printf("hello %d", num4));
	printf("\n\n");
	test = 1;
	printf(" | [%d] org_ret = %d\n", test++, printf("Hello"));
	printf(" | [%d] org_ret = %d\n", test++, printf("hello %s", str));
	printf(" | [%d] org_ret = %d\n", test++, printf("hello %c", c));
	printf(" | [%d] org_ret = %d \n", test++, printf("hello %d", num1));
	printf(" | [%d] org_ret = %d \n", test++, printf("hello %d", num2));
	printf(" | [%d] org_ret = %d \n", test++, printf("hello %d", num3));
	printf(" | [%d] org_ret = %d \n", test++, printf("hello %d", num4));
	// tester(ft_printf("Hello"), printf("Hello"), test++);
	// tester(ft_printf("hello %s", str), printf("hello %s", str), test++);
	printf("\n\nError methods:\n");
	printf(" | [ERROR 1] ft_ret = %d \n", ft_printf("hello %M", c));
	return (0);
}

// void tester (int ft_ret, int org_ret, int testcase)
// {
// 	printf("TEST [%d]\n", testcase);
// 	if (ft_ret != org_ret)
// 	{
// 		printf(_RED "STOP! Different return value (org = %d vs ft = %d)\n" _RESET, ft_ret, org_ret);
// 		exit(0);
// 	}
// 	else
// 		printf(" - same return value.");
// }
