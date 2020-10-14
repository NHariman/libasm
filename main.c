/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/09 01:28:38 by nhariman      #+#    #+#                 */
/*   Updated: 2020/10/10 18:40:07 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

void blue(void)
{
	printf("\033[1;36m");
}

void reset(void)
{
	printf("\033[0m"); 
}

static void test_all_second(void)
{
	// strcmp
	blue();
	printf("*****ft_strcmp*******");
	reset();
	test_strcmp();
	printf("\n");
	// strcpy
	blue();
	printf("*****ft_strcpy*******");
	reset();
	test_strcpy();
	printf("\n");
	// strdup
	blue();
	printf("*****ft_strdup*******");
	reset();
	test_strdup();
	printf("\n");
}

void test_all(void)
{
	blue();
	printf("Testing All Functions:\n");
	// strlen
	printf("*****ft_strlen*******");
	reset();
	test_strlen();
	printf("\n");
	// write
	blue();
	printf("*****ft_write*******");
	reset();
	test_write();
	printf("\n");
	// read
	blue();
	printf("*****ft_read*******");
	reset();
	test_read();
	printf("\n");
	test_all_second();
}

int		main(int argc, char **argv)
{
	if (argc < 2)
		test_all();
	else if (argc == 2 && !strcmp(argv[1], "strlen"))
		test_strlen();
	else if (argc == 2 && !strcmp(argv[1], "read"))
		test_read();
	else if (argc == 2 && !strcmp(argv[1], "strcmp"))
		test_strcmp();
	else if (argc == 2 && !strcmp(argv[1], "strcpy"))
		test_strcpy();
	else if (argc == 2 && !strcmp(argv[1], "strdup"))
		test_strdup();
	else if (argc == 2 && !strcmp(argv[1], "write"))
		test_write();
	else
		print_instructions();
	return (0);
}
