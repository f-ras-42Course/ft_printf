/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/19 10:22:41 by fras          #+#    #+#                 */
/*   Updated: 2023/02/16 17:33:29 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#define filename "outputresults"
#define MAX_BYTES_PRINT 128

void	tester (int ft_ret, int org_ret, int testcase);
void	printtofile(int reset);
void 	filetostring(char *dest);

int	main(void)
{
	char	*str;
	char	*empty_str;
	char	c;
	int		num1;
	int		num2;
	int		num3;
	int		num4;
	int		test;
	char	ft_output[MAX_BYTES_PRINT];
	char	org_output[MAX_BYTES_PRINT];
	int		ft_return;
	int		org_return;

	str = "string";
	empty_str = "";
	c = 'c';
	num1 = 0;
	num2 = 12346;
	num3 = -12346;
	num4 = -2147483648;
	test = 1;
	ft_return = 0;
	org_return = 0;
	test = 0;
	printtofile(0);
	printtofile(1);
	ft_return += ft_printf("Hello\n");
	ft_return += ft_printf("hello %s\n", str);
	ft_return += ft_printf("%s", empty_str);
	ft_return += ft_printf("hello %c\n", c);
	ft_return += ft_printf("hello %d\n", num1);
	ft_return += ft_printf("hello %d\n", num2);
	ft_return += ft_printf("hello %d\n", num3);
	ft_return += ft_printf("hello %d\n", num4);
	filetostring(ft_output);
	printtofile(1);
	org_return += printf("Hello\n");
	org_return += printf("hello %s\n", str);
	org_return += printf("%s", empty_str);
	org_return += printf("hello %c\n", c);
	org_return += printf("hello %d\n", num1);
	org_return += printf("hello %d\n", num2);
	org_return += printf("hello %d\n", num3);
	org_return += printf("hello %d\n", num4);
	filetostring(org_output);
	printtofile(2);
	printtofile(3);
	printf("[1]%s, [2]%s\n", ft_output, org_output);
	if (strcmp(ft_output, org_output) != 0)
		printf("TEST [%d]" _RED "STOP! Incorrect output values." _RESET, test++);
	else
		printf("TEST [%d] - same output value." _RESET, test++);
	tester(ft_return, org_return, test);
	printf("\n\nError methods (undefined behaviour):\n");
	fflush(stdout);
	printf("\n | [ERROR 1] ft_ret = %d \n", ft_printf("hello %M", c));
	fflush(stdout);
	printf("\n | [ERROR 2] ft_ret = %d \n", ft_printf("%%%"));
	fflush(stdout);
	return (0);
}

void	printtofile(int mode)
{
	static int 	stdout_fd;
	static int 	redir_fd;

	fflush(stdout);
	if (mode == 0)
		stdout_fd = dup(STDOUT_FILENO);
	if (mode == 1)
	{
		redir_fd = creat(filename, 0644);
		dup2(redir_fd, STDOUT_FILENO);
		close(redir_fd);
	}
	if (mode == 2)
	{
		dup2(stdout_fd, STDOUT_FILENO);
		close(stdout_fd);
	}
	if (mode == 3)
		remove(filename);
}

void 	filetostring(char *dest)
{
	int fd;

	fflush(stdout);
	fd = open(filename, O_RDONLY);
	read(fd, dest, MAX_BYTES_PRINT);
	close(fd);
}

void	tester (int ft_ret, int org_ret, int testcase)
{
	printf("   | TEST [%d]", testcase);
	if (ft_ret != org_ret)
	{
		printf(_RED "STOP! Different return value (ft = %d vs org = %d)\n" _RESET, ft_ret, org_ret);
		exit(0);
	}
	else
		printf(" - same return value. %d, %d\n", ft_ret, org_ret);
}
