/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_write.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/08 22:25:39 by nhariman      #+#    #+#                 */
/*   Updated: 2020/10/14 16:00:30 by nhariman      ########   odam.nl         */
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

// ssize_t		ft_write(int fd, const void *buf, size_t count);
void	test_write(void)
{
	char *sys;
	char *asem;
	int count;
	int fd;
	int fd2;

	count = 13;
	sys = "hello world!";
	asem = "hello world!";
	fd = 0;
	blue();
	printf("from stdin:\n");
	reset();
	printf("[SYS]: [%zi]\n", write(fd, sys, count));
	printf("[ASM]: [%zi]\n", ft_write(fd, asem, count));

	fd = 1;
	blue();
	printf("from stdout:\n");
	reset();
	printf("[SYS]: [%zi]\n", write(fd, sys, count));
	printf("[ASM]: [%zi]\n", ft_write(fd, asem, count));


	fd = 2;
	blue();
	printf("from sterr:\n");
	reset();
	printf("[SYS]: [%zi]\n", write(fd, sys, count));
	printf("[ASM]: [%zi]\n", ft_write(fd, asem, count));
	// fd = open("test.txt", O_RDWR | O_CREAT | O_APPEND);
	// fd2 = open("test2.txt", O_RDWR | O_CREAT | O_APPEND);
	// printf("[SYS]: [%i]\n", write(fd, sys, count));
	// printf("[ASM]: [%i]\n", ft_write(fd2, asem, count));
	
	char	s1[] = "lmao\n";

	int a = write(1, s1, sizeof(s1));
	int	b = ft_write(1, s1, sizeof(s1));
	printf("%i\n%i\n", a, b);
    a = write(FOPEN_MAX + 1, "abcdefghijklmnopqrstuvwxyz\n", 27);
	perror("write errno");
	errno = 0;
    b = ft_write(FOPEN_MAX + 1, "abcdefghijklmnopqrstuvwxyz\n", 27);
	perror("ft_write errno");
    printf("return write = %d\nreturn ft_write = %d\n", a, b);
	int	test_fd = OPEN_MAX + 1;
	if (test_fd > 2)
	{
		int c = ft_write(test_fd, "hatsssssss", 8);
		if (c < 0)
			perror("my write error");
		int d = write(test_fd, "hatsssssss", 8);
		if (d < 0)
			perror("real write error");
		printf("hats mine: %d, real: %d\n", c, d);
	}
}

int		main(void)
{
	test_write();
	return (0);
}