/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_strdup.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/08 22:25:39 by nhariman      #+#    #+#                 */
/*   Updated: 2020/10/10 21:41:39 by nhariman      ########   odam.nl         */
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

void	test_strdup(void)
{
	blue();
	printf("NULL:\n");
	reset();
	printf("[SYS]: [%s]\n", strdup(NULL));
	printf("[ASM]: [%s]\n", ft_strdup(NULL));
	blue();
	printf("\"\":\n");
	reset();
	printf("[SYS]: [%s]\n", strdup(""));
	printf("[ASM]: [%s]\n", ft_strdup(""));
	blue();
	printf("\"\\0\":\n");
	reset();
	printf("[SYS]: [%s]\n", strdup("\0"));
	printf("[ASM]: [%s]\n", ft_strdup("\0"));
	blue();
	printf("hello world!:\n");
	reset();
	printf("[SYS]: [%s]\n", strdup("hello world!"));
	printf("[ASM]: [%s]\n", ft_strdup("hello world!"));
	blue();
	printf("fkdalhfld;hfla;fhkdjfl;kdjflj49r784570wutkrthj8y(*^*(^&*^&*%TY*HU(H&&%^*TUIY*(Y*(UYuhfijdhafuh4hf98fhjhg9hrgjdhf9fhejh9ofhghrgohgijgk:\n");
	reset();
	printf("[SYS]: [%s]\n", strdup("fkdalhfld;hfla;fhkdjfl;kdjflj49r784570wutkrthj8y(*^*(^&*^&*%TY*HU(H&&%^*TUIY*(Y*(UYuhfijdhafuh4hf98fhjhg9hrgjdhf9fhejh9ofhghrgohgijgk"));
	printf("[ASM]: [%s]\n", ft_strdup("fkdalhfld;hfla;fhkdjfl;kdjflj49r784570wutkrthj8y(*^*(^&*^&*%TY*HU(H&&%^*TUIY*(Y*(UYuhfijdhafuh4hf98fhjhg9hrgjdhf9fhejh9ofhghrgohgijgk"));
}
