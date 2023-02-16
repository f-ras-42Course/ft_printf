/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/19 10:22:41 by fras          #+#    #+#                 */
/*   Updated: 2023/02/16 15:38:40 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <fcntl.h>
#define filename "outputresults"
#define MAX_BYTES_PRINT 128

void	tester (int ft_ret, int org_ret, int testcase);
void	printtofile(int reset);
void 	filetostring(char *dest);

int	main(void)
{
	char	*str;
	char	c;
	int		num1;
	int		num2;
	int		num3;
	int		num4;
	int		test;
	char	ft_output[MAX_BYTES_PRINT];
	char	org_output[MAX_BYTES_PRINT];
	// int		ft_return;
	// int		org_return;

	str = "string";
	c = 'c';
	num1 = 0;
	num2 = 12346;
	num3 = -12346;
	num4 = -2147483648;
	test = 1;
	// ft_printf("Hello");
	// printf(" | [%d] ft_ret = %d \n", test++, ft_printf("hello %s", str));
	// printf(" | [%d] ft_ret = %d \n", test++, ft_printf("hello %c", c));
	// printf(" | [%d] ft_ret = %d \n", test++, ft_printf("hello %d", num1));
	// printf(" | [%d] ft_ret = %d \n", test++, ft_printf("hello %d", num2));
	// printf(" | [%d] ft_ret = %d \n", test++, ft_printf("hello %d", num3));
	// printf(" | [%d] ft_ret = %d \n", test++, ft_printf("hello %d", num4));
	// printf("\n\n");
	// test = 1;
	// printf(" | [%d] org_ret = %d\n", test++, printf("Hello"));
	// printf(" | [%d] org_ret = %d\n", test++, printf("hello %s", str));
	// printf(" | [%d] org_ret = %d\n", test++, printf("hello %c", c));
	// printf(" | [%d] org_ret = %d \n", test++, printf("hello %d", num1));
	// printf(" | [%d] org_ret = %d \n", test++, printf("hello %d", num2));
	// printf(" | [%d] org_ret = %d \n", test++, printf("hello %d", num3));
	// printf(" | [%d] org_ret = %d \n", test++, printf("hello %d", num4));
	// printf("\n\n");
	test = 1;
	printtofile(0);
	printtofile(1);
	ft_printf("HelloF\n");
	filetostring(ft_output);
	printtofile(1);
	ft_printf("HelloO\n");
	filetostring(org_output);
	printtofile(2);
	test++;
	tester(ft_printf("1hello %s\n", str), printf("2hello %s\n", str), test++);
	printtofile(3);
	printf("\n\nError methods:\n");
	printf(" | [ERROR 1] ft_ret = %d \n", ft_printf("hello %M", c));
	printf("[1]%s, [2]%s\n", ft_output, org_output);
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

	fd = open(filename, O_RDONLY);
	read(fd, dest, MAX_BYTES_PRINT);
	close(fd);
}

void	tester (int ft_ret, int org_ret, int testcase)
{
	printf("   | TEST [%d]", testcase);
	if (ft_ret != org_ret)
	{
		printf(_RED "STOP! Different return value (org = %d vs ft = %d)\n" _RESET, ft_ret, org_ret);
		exit(0);
	}
	else
		printf(" - same return value.\n");
}
