/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_read.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/08 22:25:39 by nhariman      #+#    #+#                 */
/*   Updated: 2020/10/14 17:09:25 by nhariman      ########   odam.nl         */
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

// ssize_t		ft_read(int fd, void *buf, size_t count);
void	test_read(void)
{
    int		readfd1;
    int		readfd2;
    int		readfd;
    int		error_read;
    char	*buf;

    buf = malloc(1000);
    printf("\ntest 1: normal test\n");
    readfd1 = open("ft_read.s", O_RDONLY);
    readfd2 = open("ft_read.s", O_RDONLY);

    readfd = read(readfd1, buf, 4);
    printf("   read:    read return: %d\n", readfd);
    readfd = ft_read(readfd2, buf, 4);
    printf("ft_read: ft_read return: %d\n", readfd);

    printf("\ntest 2: no real text\n");
    readfd = open("empty.txt", O_RDONLY);
    readfd = ft_read(readfd, buf, 4);
    printf("ft_read:    return read: %d\n", readfd);
    printf("   read: return ft_read: -1");

    printf("\n\ntest 3: long text\n");
    readfd = open("notes.txt", O_RDONLY);
    readfd1 = read(readfd, buf, 1000);
    printf("   read:    read return: %d\n", readfd);
    readfd2 = ft_read(readfd, buf, 1000);
    printf("ft_read: ft_read return: %d\n", readfd);

    printf("\n\ntest 3: errno1\n");
    char	buf1[21];
    char	buf2[21];
    int	fd = open("empty.txt", O_RDONLY);
    int	a = read(333, buf1, 20);
    errno = 100;
    int b = ft_read(333, buf2, 20);
	perror("ft_read errno");
    perror("   read errno");

    printf("\n\ntest 4: errno2\n");
    printf("return ft_read = %d\n", b);
    printf("return    read = %d\n", a);
}

int main(void)
{
	test_read();
	return (0);
}
