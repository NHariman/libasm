/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/09 01:28:38 by nhariman      #+#    #+#                 */
/*   Updated: 2020/10/14 17:29:08 by nhariman      ########   odam.nl         */
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
	printf("*****ft_strlen*******\n");
	printf("\"\":\n");
	reset();
	printf("[SYS]: [%lu]\n", strlen(""));
	printf("[ASM]: [%lu]\n", ft_strlen(""));
	blue();
	printf("\"\\0\":\n");
	reset();
	printf("[SYS]: [%lu]\n", strlen("\0"));
	printf("[ASM]: [%lu]\n", ft_strlen("\0"));
	blue();
	printf("hello world!:\n");
	reset();
	printf("[SYS]: [%lu]\n", strlen("hello world!"));
	printf("[ASM]: [%lu]\n", ft_strlen("hello world!"));
	blue();
	printf("fkdalhfld;hfla;fhkdjfl;kdjflj49r784570wutkrthj8y(*^*(^&*^&*TY*HU(H&&^*TUIY*(Y*(UYuhfijdhafuh4hf98fhjhg9hrgjdhf9fhejh9ofhghrgohgijgk:\n");
	reset();
	printf("[SYS]: [%lu]\n", strlen("fkdalhfld;hfla;fhkdjfl;kdjflj49r784570wutkrthj8y(*^*(^&*^&*TY*HU(H&&^*TUIY*(Y*(UYuhfijdhafuh4hf98fhjhg9hrgjdhf9fhejh9ofhghrgohgijgk:\n"));
	printf("[ASM]: [%lu]\n", ft_strlen("fkdalhfld;hfla;fhkdjfl;kdjflj49r784570wutkrthj8y(*^*(^&*^&*TY*HU(H&&^*TUIY*(Y*(UYuhfijdhafuh4hf98fhjhg9hrgjdhf9fhejh9ofhghrgohgijgk:\n"));
}

void test_strcmp(void)
{
	blue();
	printf("*****ft_strcmp*******\n");
	reset();
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

void	test_strcpy(void)
{
	char *str = malloc(30);

	blue();
	printf("*****ft_strcpy*******\n");
	reset();
	blue();
	printf("str1 is malloced with size 30\n\n");
	printf("s2: buff:\n");
	reset();
	printf("[SYS]: [%s]\n", strcpy(str, "buff"));
	printf("[ASM]: [%s]\n", ft_strcpy(str, "buff"));
	blue();
	printf("s2: bink:\n");
	reset();
	printf("[SYS]: [%s]\n", strcpy(str, "bink"));
	printf("[ASM]: [%s]\n", ft_strcpy(str, "bink"));
	blue();
	printf("s2: binkdffd:\n");
	reset();
	printf("[SYS]: [%s]\n", strcpy(str, "binkdffd"));
	printf("[ASM]: [%s]\n", ft_strcpy(str, "binkdffd"));
	blue();
	printf("s2: cat:\n");
	reset();
	printf("[SYS]: [%s]\n", strcpy(str, "cat"));
	printf("[ASM]: [%s]\n", ft_strcpy(str, "cat"));
	blue();
	printf("s2: test:\n");
	reset();
	printf("[SYS]: [%s]\n", strcpy(str, "test"));
	printf("[ASM]: [%s]\n", ft_strcpy(str, "test"));
	blue();
	printf("s2: \"\":\n");
	reset();
	printf("[SYS]: [%s]\n", strcpy(str, ""));
	printf("[ASM]: [%s]\n", ft_strcpy(str, ""));
	blue();
	printf("s2: \"\\0\":\n");
	reset();
	printf("[SYS]: [%s]\n", strcpy(str, "\0"));
	printf("[ASM]: [%s]\n", ft_strcpy(str, "\0"));
	blue();
	printf("s2: test:\n");
	reset();
	printf("[SYS]: [%s]\n", strcpy(str, "test"));
	printf("[ASM]: [%s]\n", ft_strcpy(str, "test"));
}

void	test_strdup(void)
{
	blue();
	printf("*****ft_strdup*******\n");
	reset();
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
	printf("fkdalhfld;hfla;fhkdjfl;kdjflj49r784570wutkrthj8y(*^*(^&*^&*TY*HU(H&&^*TUIY*(Y*(UYuhfijdhafuh4hf98fhjhg9hrgjdhf9fhejh9ofhghrgohgijgk:\n");
	reset();
	printf("[SYS]: [%s]\n", strdup("fkdalhfld;hfla;fhkdjfl;kdjflj49r784570wutkrthj8y(*^*(^&*^&*TY*HU(H&&^*TUIY*(Y*(UYuhfijdhafuh4hf98fhjhg9hrgjdhf9fhejh9ofhghrgohgijgk:\n"));
	printf("[ASM]: [%s]\n", ft_strdup("fkdalhfld;hfla;fhkdjfl;kdjflj49r784570wutkrthj8y(*^*(^&*^&*TY*HU(H&&^*TUIY*(Y*(UYuhfijdhafuh4hf98fhjhg9hrgjdhf9fhejh9ofhghrgohgijgk:\n"));
}

void	test_read(void)
{
    int		readfd1;
    int		readfd2;
    int		readfd;
    int		error_read;
    char	*buf;

	blue();
	printf("*****ft_read*******\n");
	reset();
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

void	test_write(void)
{
	char *sys;
	char *asem;
	int count;
	int fd;
	int fd2;
	blue();
	printf("*****ft_write*******\n");
	reset();
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

static void test_all_second(void)
{
	// strcmp

	test_strcmp();
	printf("\n");
	// strcpy

	test_strcpy();
	printf("\n");
	// strdup

	test_strdup();
	printf("\n");
}

void test_all(void)
{
	blue();
	printf("Testing All Functions:\n");
	// strlen
	reset();
	test_strlen();
	printf("\n");
	// write

	test_write();
	printf("\n");
	// read
	test_read();
	printf("\n");
	test_all_second();
}

void	print_instructions(void)
{
	printf("Main is able to test one function at a time, or all of them at once.\n");
	printf("commands:\n");
	printf("all | strlen | read | strcmp | strcpy | strdup | write\n");
}


int		main(int argc, char **argv)
{
	if (argc < 2)
		print_instructions();
	else if (argc == 2 && !strcmp(argv[1], "strlen"))
		test_strlen();
	else if (argc == 2 && !strcmp(argv[1], "read"))
		test_read();
	else if (argc == 2 && !strcmp(argv[1], "strcmp"))
		test_strcmp();
	else if (argc == 2 && !strcmp(argv[1], "strcpy"))
		test_strcpy();
	else if (argc == 2 && !strcmp(argv[1], "strdup"))
		test_strdup();
	else if (argc == 2 && !strcmp(argv[1], "write"))
		test_write();
	else if (argc == 2 && !strcmp(argv[1], "all"))
		test_all();
	else
	{
		printf("command not recognised\n");
		print_instructions();
	}
	
	
	return (0);
}
