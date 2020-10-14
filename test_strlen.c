/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_strlen.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/08 22:25:39 by nhariman      #+#    #+#                 */
/*   Updated: 2020/10/10 21:28:21 by nhariman      ########   odam.nl         */
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

void	test_strlen(void)
{
	blue();
	printf("NULL:\n");
	reset();
	printf("[SYS]: [%i]\n", strlen(NULL));
	printf("[ASM]: [%i]\n", ft_strlen(NULL));
	blue();
	printf("\"\":\n");
	reset();
	printf("[SYS]: [%i]\n", strlen(""));
	printf("[ASM]: [%i]\n", ft_strlen(""));
	blue();
	printf("\"\\0\":\n");
	reset();
	printf("[SYS]: [%i]\n", strlen("\0"));
	printf("[ASM]: [%i]\n", ft_strlen("\0"));
	blue();
	printf("hello world!:\n");
	reset();
	printf("[SYS]: [%i]\n", strlen("hello world!"));
	printf("[ASM]: [%i]\n", ft_strlen("hello world!"));
	blue();
	printf("fkdalhfld;hfla;fhkdjfl;kdjflj49r784570wutkrthj8y(*^*(^&*^&*%TY*HU(H&&%^*TUIY*(Y*(UYuhfijdhafuh4hf98fhjhg9hrgjdhf9fhejh9ofhghrgohgijgk:\n");
	reset();
	printf("[SYS]: [%i]\n", strlen("fkdalhfld;hfla;fhkdjfl;kdjflj49r784570wutkrthj8y(*^*(^&*^&*%TY*HU(H&&%^*TUIY*(Y*(UYuhfijdhafuh4hf98fhjhg9hrgjdhf9fhejh9ofhghrgohgijgk"));
	printf("[ASM]: [%i]\n", ft_strlen("fkdalhfld;hfla;fhkdjfl;kdjflj49r784570wutkrthj8y(*^*(^&*^&*%TY*HU(H&&%^*TUIY*(Y*(UYuhfijdhafuh4hf98fhjhg9hrgjdhf9fhejh9ofhghrgohgijgk"));
}
