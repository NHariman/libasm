/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_strcpy.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/08 22:25:39 by nhariman      #+#    #+#                 */
/*   Updated: 2020/10/14 15:08:29 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <limits.h>
#include <fcntl.h>
#include "libasm.h"

void blue(void)
{
	printf("\033[1;36m");
}

void reset(void)
{
	printf("\033[0m"); 
}

void	test_strcpy(void)
{
	char *str = malloc(30);

	blue();
	printf("str1 is malloced with size 30\n\n");
	printf("s2: buff:\n");
	reset();
	printf("[SYS]: [%s]\n", strcpy(str, "buff"));
	printf("[ASM]: [%s]\n", ft_strcpy(str, "buff"));
	blue();
	printf("s2: bink:\n");
	reset();
	printf("[SYS]: [%s]\n", strcpy(str, "bink"));
	printf("[ASM]: [%s]\n", ft_strcpy(str, "bink"));
	blue();
	printf("s2: binkdffd:\n");
	reset();
	printf("[SYS]: [%s]\n", strcpy(str, "binkdffd"));
	printf("[ASM]: [%s]\n", ft_strcpy(str, "binkdffd"));
	blue();
	printf("s2: cat:\n");
	reset();
	printf("[SYS]: [%s]\n", strcpy(str, "cat"));
	printf("[ASM]: [%s]\n", ft_strcpy(str, "cat"));
	blue();
	printf("s2: test:\n");
	reset();
	printf("[SYS]: [%s]\n", strcpy(str, "test"));
	printf("[ASM]: [%s]\n", ft_strcpy(str, "test"));
	blue();
	printf("s2: \"\":\n");
	reset();
	printf("[SYS]: [%s]\n", strcpy(str, ""));
	printf("[ASM]: [%s]\n", ft_strcpy(str, ""));
	blue();
	printf("s2: \"\\0\":\n");
	reset();
	printf("[SYS]: [%s]\n", strcpy(str, "\0"));
	printf("[ASM]: [%s]\n", ft_strcpy(str, "\0"));
	blue();
	printf("s2: test:\n");
	reset();
	printf("[SYS]: [%s]\n", strcpy(str, "test"));
	printf("[ASM]: [%s]\n", ft_strcpy(str, "test"));
}

int		main(void)
{
	test_strcpy();
	return (0);
}