/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_read.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/08 22:25:39 by nhariman      #+#    #+#                 */
/*   Updated: 2020/10/10 22:03:59 by nhariman      ########   odam.nl         */
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

// ssize_t		ft_read(int fd, void *buf, size_t count);
void	test_read(void)
{
	char sys[100];
	char asem[100];
	int count;
	int fd;

	count = 100;
	fd = 0;
	blue();
	printf("from stdin:\n");
	reset();
	printf("[SYS]: [%i], buf: %s\n", read(fd, sys, count), sys);
	printf("[ASM]: [%i], buf: %s\n", ft_read(fd, asem, count), asem);
	free(sys);
	free(asem);
	fd = 1;
	blue();
	printf("from stdout:\n");
	reset();
	printf("[SYS]: [%i], buf: %s\n", read(fd, sys, count), sys);
	printf("[ASM]: [%i], buf: %s\n", ft_read(fd, asem, count), asem);
	free(sys);
	free(asem);

	fd = 2;
	blue();
	printf("from stdout:\n");
	printf("[SYS]: [%i], buf: %s\n", read(fd, sys, count), sys);
	printf("[ASM]: [%i], buf: %s\n", ft_read(fd, asem, count), asem);
	free(sys);
	free(asem);
}
