/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_mine.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/12 11:57:30 by ybakker       #+#    #+#                 */
/*   Updated: 2020/10/12 15:02:04 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/04 14:44:55 by ybakker       #+#    #+#                 */
/*   Updated: 2020/09/01 17:10:22 by ybakker       ########   odam.nl         */
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

void    read_test(void)
{
    printf("\n-----------------\n");
    printf("testing ft_read\n");

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
    readfd = open("no_real_file.txt", O_RDONLY);
    readfd = ft_read(readfd, buf, 4);
    printf("ft_read:    return read: %d\n", readfd);
    printf("   read: return ft_read: -1");

    printf("\n\ntest 3: long text\n");
    readfd = open("long_text.txt", O_RDONLY);
    readfd = read(readfd, buf, 1000);
    printf("   read:    read return: %d\n", readfd);
    readfd = ft_read(readfd, buf, 1000);
    printf("ft_read: ft_read return: %d\n", readfd);

    printf("\n\ntest 3: errno1\n");
    char	buf1[21];
    char	buf2[21];
    int	fd = open("no_real_file.txt", O_RDONLY);
    int	a = read(333, buf1, 20);
    errno = 100;
    int b = ft_read(333, buf2, 20);
	perror("ft_read errno");
    perror("   read errno");

    printf("\n\ntest 4: errno2\n");
    printf("return ft_read = %d\n", b);
    printf("return    read = %d\n", a);
    printf("\n-----------------\n");
}

void    strlen_test(void)
{
    printf("\n-----------------\n");
    printf("testing ft_strlen\n");
    printf("returns the lenght of a string\n");
    int		len;
    char    *str = "testing line";

	printf("\n   test 1: some line\n");
	len = strlen(str);
	printf("   strlen: %d\n", len);
	len = ft_strlen(str);
	printf("ft_strlen: %d\n", len);

	printf("\n   test 2: no line\n");
	len = strlen("");
	printf("   strlen: %d\n", len);
	len = ft_strlen("");
	printf("ft_strlen: %d\n", len);
    printf("\n-----------------\n");
}

void    strcmp_test(void)
{
    printf("\n-----------------\n");
    printf("testing strcmp\n");
    printf("compares two inputs and see if they match, return -1, 1 or 0\n");
	int		difference;

	printf("\ntest 1: difference\n");
	difference = strcmp("compare1", "compare2");
	printf("   strcmp: %d\n", difference);
	difference = ft_strcmp("compare1", "compare2");
	printf("ft_strcmp: %d\n", difference);

	printf("\ntest 2: numbers symbols\n");
	difference = strcmp("//4", "/4");
	printf("   strcmp: %d\n", difference);
	difference = ft_strcmp("//4", "/4");
	printf("ft_strcmp: %d\n", difference);

	printf("\ntest 3: single character\n");
	difference = strcmp("a", "a");
	printf("   strcmp: %d\n", difference);
	difference = ft_strcmp("a", "a");
	printf("ft_strcmp: %d\n", difference);

	printf("\ntest 4: same\n");
	difference = strcmp("compare1", "compare1");
	printf("   strcmp: %d\n", difference);
	difference = ft_strcmp("compare1", "compare1");
	printf("ft_strcmp: %d\n", difference);

    printf("\ntest 5: one difference end\n");
	difference = strcmp("1111111", "1111112");
	printf("   strcmp: %d\n", difference);
	difference = ft_strcmp("1111111", "1111112");
	printf("ft_strcmp: %d\n", difference);

    printf("\ntest 6: one difference end\n");
	difference = strcmp("1111112", "1111111");
	printf("   strcmp: %d\n", difference);
	difference = ft_strcmp("1111112", "1111111");
	printf("ft_strcmp: %d\n", difference);
    printf("\n-----------------\n");
}

void    strcpy_test(void)
{
    printf("\n-----------------\n");
    printf("testing strcmp\n");

    char    *str = malloc(30);

    printf("\ntest 1: string\n");
	strcpy(str, "dit is de eerste test");
	printf("   strcpy: %s\n", str);
	ft_strcpy(str, "dit is de eerste test");
	printf("ft_strcpy: %s\n", str);

	printf("\ntest 2: one character\n");
	strcpy(str, "a");
	printf("   strcpy: %s\n", str);
	ft_strcpy(str, "a");
	printf("ft_strcpy: %s\n", str);

	printf("\ntest 3: nothing\n");
	strcpy(str, "");
	printf("   strcpy: %s\n", str);
	ft_strcpy(str, "");
	printf("ft_strcpy: %s\n", str);
    printf("\n-----------------\n");
}

void    strdup_test(void)
{
    printf("\n-----------------\n");
    printf("testing strdup\n");
    char	*str1;
    char    *str2;

	printf("\n test 1:\n");
	str1 = strdup("hoi");
	printf("   strdup: %s\n", str1);
	str2 = ft_strdup("hoi");
	printf("ft_strdup: %s\n", str2);
    int     difference = ft_strcmp(str1, str2);
    printf("compare test 1: %d\n", difference);

	printf("\ntest 2:\n");
	str1 = strdup("");
	printf("   strdup: %s\n", str1);
	str2 = ft_strdup("");
	printf("ft_strdup: %s\n", str2);
    difference = ft_strcmp(str1, str2);
    printf("compare test 2: %d\n", difference);

	printf("\ntest 3:\n");
	str1 = strdup("strcmp(buffer_read, buffer_ft_read) = 0");
	printf("   strdup: %s\n", str1);
	str2 = strdup("strcmp(buffer_read, buffer_ft_read) = 0");
	printf("ft_strdup: %s\n", str2);
    difference = ft_strcmp(str1, str2);
    printf("compare test 3: %d\n", difference);
    printf("\n-----------------\n");
}

void    write_test(void)
{
    printf("\n-----------------\n");
    printf("testing write\n");
	char	s1[] = "yeet\n";

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
	printf("\n");
    printf("\n-----------------\n");
}

int	main(void)
{
    read_test();
    strlen_test();
    strcmp_test();
    strcpy_test();
    strdup_test();
    write_test();
}
