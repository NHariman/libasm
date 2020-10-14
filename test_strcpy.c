/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_strcpy.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/08 22:25:39 by nhariman      #+#    #+#                 */
/*   Updated: 2020/10/10 21:42:14 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <stdio.h>
#include <string.h>

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
	blue();
	printf("s1: test:\n");
	printf("s2: test:\n");
	reset();
	printf("[SYS]: [%s]\n", strcpy("test", "test"));
	printf("[ASM]: [%s]\n", ft_strcpy("test", "test"));
	blue();
	printf("s1: test:\n");
	printf("s2: bink:\n");
	reset();
	printf("[SYS]: [%s]\n", strcpy("test", "bink"));
	printf("[ASM]: [%s]\n", ft_strcpy("test", "bink"));
	blue();
	printf("s1: test:\n");
	printf("s2: binkdffd:\n");
	reset();
	printf("[SYS]: [%s]\n", strcpy("test", "binkdffd"));
	printf("[ASM]: [%s]\n", ft_strcpy("test", "binkdffd"));
	blue();
	printf("s1: notest:\n");
	printf("s2: cat:\n");
	reset();
	printf("[SYS]: [%s]\n", strcpy("notest", "cat"));
	printf("[ASM]: [%s]\n", ft_strcpy("notest", "cat"));
	blue();
	printf("s1: test:\n");
	printf("s2: NULL:\n");
	reset();
	printf("[SYS]: [%s]\n", strcpy("test", NULL));
	printf("[ASM]: [%s]\n", ft_strcpy("test", NULL));
	blue();
	printf("s1: NULL:\n");
	printf("s2: test:\n");
	reset();
	printf("[SYS]: [%s]\n", strcpy(NULL, "test"));
	printf("[ASM]: [%s]\n", ft_strcpy(NULL, "test"));
	blue();
	printf("s1: \"\":\n");
	printf("s2: test:\n");
	reset();
	printf("[SYS]: [%s]\n", strcpy("", "test"));
	printf("[ASM]: [%s]\n", ft_strcpy("", "test"));
	blue();
	printf("s1: test:\n");
	printf("s2: \"\":\n");
	reset();
	printf("[SYS]: [%s]\n", strcpy("test", ""));
	printf("[ASM]: [%s]\n", ft_strcpy("test", ""));
	blue();
	printf("s1: test:\n");
	printf("s2: \"\\0\":\n");
	reset();
	printf("[SYS]: [%s]\n", strcpy("test", "\0"));
	printf("[ASM]: [%s]\n", ft_strcpy("test", "\0"));
	blue();
	printf("s1: \"\\0\":\n");
	printf("s2: test:\n");
	reset();
	printf("[SYS]: [%s]\n", strcpy("\0", "test"));
	printf("[ASM]: [%s]\n", ft_strcpy("\0", "test"));
}
