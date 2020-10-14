/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_write.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/08 22:25:39 by nhariman      #+#    #+#                 */
/*   Updated: 2020/10/10 22:09:48 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <stdio.h>
#include <errno.h>
#include <unistd.h>

void blue(void)
{
	printf("\033[1;36m");
}

void reset(void)
{
	printf("\033[0m"); 
}

// ssize_t		ft_write(int fd, const void *buf, size_t count);
void	test_write(void)
{
	char *sys;
	char *asem;
	int count;
	int fd;

	count = 13;
	sys = "hello world!";
	asem = "hello world!";
	fd = 0;
	blue();
	printf("from stdin:\n");
	reset();
	printf("[SYS]: [%i]\n", write(fd, sys, count));
	printf("[ASM]: [%i]\n", ft_write(fd, asem, count));
	free(sys);
	free(asem);
	fd = 1;
	blue();
	printf("from stdout:\n");
	reset();
	printf("[SYS]: [%i]\n", write(fd, sys, count));
	printf("[ASM]: [%i]\n", ft_write(fd, asem, count));
	free(sys);
	free(asem);

	fd = 2;
	blue();
	printf("from stdout:\n");
	printf("[SYS]: [%i]\n", write(fd, sys, count));
	printf("[ASM]: [%i]\n", ft_write(fd, asem, count));
	free(sys);
	free(asem);
}
