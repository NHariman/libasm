/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_strlen.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/08 22:25:39 by nhariman      #+#    #+#                 */
/*   Updated: 2020/10/14 14:18:55 by nhariman      ########   odam.nl         */
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

void	test_strlen(void)
{
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

int	main(void)
{
	test_strlen();
	return (0);
}
