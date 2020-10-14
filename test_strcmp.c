/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_strcmp.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/08 22:25:39 by nhariman      #+#    #+#                 */
/*   Updated: 2020/10/10 21:13:31 by nhariman      ########   odam.nl         */
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

// ft_strcmp(const char *s1, const char *s2);
void test_strcmp(void)
{
	blue();
	printf("s1: test:\n");
	printf("s2: test:\n");
	reset();
	printf("[SYS]: [%i]\n", strcmp("test", "test"));
	printf("[ASM]: [%i]\n", ft_strcmp("test", "test"));
	blue();
	printf("s1: test:\n");
	printf("s2: notest:\n");
	reset();
	printf("[SYS]: [%i]\n", strcmp("test", "notest"));
	printf("[ASM]: [%i]\n", ft_strcmp("test", "notest"));
	blue();
	printf("s1: notest:\n");
	printf("s2: test:\n");
	reset();
	printf("[SYS]: [%i]\n", strcmp("notest", "test"));
	printf("[ASM]: [%i]\n", ft_strcmp("notest", "test"));
	blue();
	printf("s1: test:\n");
	printf("s2: NULL:\n");
	reset();
	printf("[SYS]: [%i]\n", strcmp("test", NULL));
	printf("[ASM]: [%i]\n", ft_strcmp("test", NULL));
	blue();
	printf("s1: NULL:\n");
	printf("s2: test:\n");
	reset();
	printf("[SYS]: [%i]\n", strcmp(NULL, "test"));
	printf("[ASM]: [%i]\n", ft_strcmp(NULL, "test"));
	blue();
	printf("s1: \"\":\n");
	printf("s2: test:\n");
	reset();
	printf("[SYS]: [%i]\n", strcmp("", "test"));
	printf("[ASM]: [%i]\n", ft_strcmp("", "test"));
	blue();
	printf("s1: test:\n");
	printf("s2: \"\":\n");
	reset();
	printf("[SYS]: [%i]\n", strcmp("test", ""));
	printf("[ASM]: [%i]\n", ft_strcmp("test", ""));
	blue();
	printf("s1: test:\n");
	printf("s2: \"\\0\":\n");
	reset();
	printf("[SYS]: [%i]\n", strcmp("test", "\0"));
	printf("[ASM]: [%i]\n", ft_strcmp("test", "\0"));
	blue();
	printf("s1: \"\\0\":\n");
	printf("s2: test:\n");
	reset();
	printf("[SYS]: [%i]\n", strcmp("\0", "test"));
	printf("[ASM]: [%i]\n", ft_strcmp("\0", "test"));
}
