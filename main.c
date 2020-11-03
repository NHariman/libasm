/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/09 01:28:38 by nhariman      #+#    #+#                 */
/*   Updated: 2020/11/03 13:50:39 by nhariman      ########   odam.nl         */
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
	reset();
	//uncomment to check for the NULL segfault, run full, then comment out the [SYS], in both cases the program should segfault.
	// blue();
	// printf("NULL:\n");
	// reset();
	// printf("[SYS]: [%lu]\n", strlen(NULL));
	// printf("[ASM]: [%lu]\n", ft_strlen(NULL));
	blue();
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
	//uncomment to check for the NULL segfault, run full, then comment out the [SYS], in both cases the program should segfault.
	// blue();
	// printf("s1: NULL:\n");
	// printf("s2: test:\n");
	// reset();
	// printf("[SYS]: [%i]\n", strcmp(NULL, "test"));
	// printf("[ASM]: [%i]\n", ft_strcmp(NULL, "test"));
	//uncomment to check for the NULL segfault, run full, then comment out the [SYS], in both cases the program should segfault.
	// blue();
	// printf("s1: test:\n");
	// printf("s2: NULL:\n");
	// reset();
	// printf("[SYS]: [%i]\n", strcmp("test", NULL));
	// printf("[ASM]: [%i]\n", ft_strcmp("test", NULL));
	//uncomment to check for the NULL segfault, run full, then comment out the [SYS], in both cases the program should segfault.
	// blue();
	// printf("s1: NULL:\n");
	// printf("s2: NULL:\n");
	// reset();
	// printf("[SYS]: [%i]\n", strcmp(NULL, NULL));
	// printf("[ASM]: [%i]\n", ft_strcmp(NULL, NULL));
}

void	test_strcpy(void)
{
	char *str = malloc(30);
	char *str5 = malloc(30);

	blue();
	printf("*****ft_strcpy*******\n");
	reset();
	//uncomment to check for the NULL segfault, run full, then comment out the [SYS], in both cases the program should segfault.
	// blue();
	// printf("s1: NULL\n");
	// printf("s2: buff:\n");
	// reset();
	// printf("[SYS]: [%s]\n", strcpy(NULL, "buff"));
	// printf("[ASM]: [%s]\n", ft_strcpy(NULL, "buff"));
	//uncomment to check for the NULL segfault, run full, then comment out the [SYS], in both cases the program should segfault.
	// blue();
	// printf("str1 is malloced with size 30\n");
	// printf("s2: NULL\n");
	// reset();
	// printf("[SYS]: [%s]\n", strcpy(str, NULL));
	// printf("[ASM]: [%s]\n", ft_strcpy(str, NULL));
	//uncomment to check for the NULL segfault, run full, then comment out the [SYS], in both cases the program should segfault.
	// blue();
	// printf("NULL\n\n");
	// printf("s2: NULL\n");
	// reset();
	// printf("[SYS]: [%s]\n", strcpy(NULL, NULL));
	// printf("[ASM]: [%s]\n", ft_strcpy(NULL, NULL));
	//uncomment to check for the propper error, run full, then comment out the [SYS], in both cases the program should return the error:
	// bus error
	// blue();
	// printf("s1: test\n");
	// printf("s2: testdfdfd\n");
	// reset();
	// printf("[SYS]: [%s]\n", strcpy("test", "testdfdfd"));
	// printf("[ASM]: [%s]\n", ft_strcpy("test", "testdfdfd"));
	blue();
	printf("str1 is malloced with size 30\n\n");
	printf("s2: buff:\n");
	reset();
	printf("[SYS]: [%s]\n", strcpy(str, "buff"));
	printf("[ASM]: [%s]\n", ft_strcpy(str5, "buff"));
	blue();
	printf("s2: bink:\n");
	reset();
	printf("[SYS]: [%s]\n", strcpy(str, "bink"));
	printf("[ASM]: [%s]\n", ft_strcpy(str5, "bink"));
	blue();
	printf("s2: binkdffd:\n");
	reset();
	printf("[SYS]: [%s]\n", strcpy(str, "binkdffd"));
	printf("[ASM]: [%s]\n", ft_strcpy(str5, "binkdffd"));
	blue();
	printf("s2: cat:\n");
	reset();
	printf("[SYS]: [%s]\n", strcpy(str, "cat"));
	printf("[ASM]: [%s]\n", ft_strcpy(str5, "cat"));
	blue();
	printf("s2: test:\n");
	reset();
	printf("[SYS]: [%s]\n", strcpy(str, "test1"));
	printf("[ASM]: [%s]\n", ft_strcpy(str5, "test1"));
	blue();
	printf("s2: \"\":\n");
	reset();
	printf("[SYS]: [%s]\n", strcpy(str, ""));
	printf("[ASM]: [%s]\n", ft_strcpy(str5, ""));
	blue();
	printf("s2: \"\\0\":\n");
	reset();
	printf("[SYS]: [%s]\n", strcpy(str, "\0"));
	printf("[ASM]: [%s]\n", ft_strcpy(str5, "\0"));
	blue();
	printf("s2: test:\n");
	reset();
	char *str2 = malloc(30);
	printf("[SYS]: [%s]\n", strcpy(str2, "test"));
	printf("[ASM]: [%s]\n", ft_strcpy(str5, "test"));
	free(str);
	free(str2);
	char *str4 = malloc(5);
	char *str3 = malloc(5);
	blue();
	printf("s1: str malloced 5\n");
	printf("s2: testdfdfd\n");
	reset();
	printf("[SYS]: [%s]\n", strcpy(str4, "testdfdfd"));
	printf("[ASM]: [%s]\n", ft_strcpy(str3, "testdfdfd"));
	free(str4);
	free(str3);
	free(str5);
}

void	test_strdup(void)
{
	char *sys;
	char *asem;
	blue();
	printf("*****ft_strdup*******\n");
	reset();
	//uncomment to check for the NULL segfault, run full, then comment out the [SYS], in both cases the program should segfault.
	// blue();
	// printf("NULL:\n");
	// reset();
	// printf("[SYS]: [%s]\n", strdup(NULL));
	// printf("[ASM]: [%s]\n", ft_strdup(NULL));
	blue();
	printf("\"\":\n");
	reset();
	sys = strdup("");
	asem = ft_strdup("");
	printf("[SYS]: [%s]\n", sys);
	printf("[ASM]: [%s]\n", asem);
	free(sys);
	free(asem);
	blue();
	printf("\"\\0\":\n");
	reset();
	sys = strdup("\0");
	asem = ft_strdup("\0");
	printf("[SYS]: [%s]\n", sys);
	printf("[ASM]: [%s]\n", asem);
	free(sys);
	free(asem);
	blue();
	printf("hello world!:\n");
	reset();
	sys = strdup("hello world!");
	asem = ft_strdup("hello world!");
	printf("[SYS]: [%s]\n", sys);
	printf("[ASM]: [%s]\n", asem);
	free(sys);
	free(asem);
	blue();
	printf("fkdalhfld;hfla;fhkdjfl;kdjflj49r784570wutkrthj8y(*^*(^&*^&*TY*HU(H&&^*TUIY*(Y*(UYuhfijdhafuh4hf98fhjhg9hrgjdhf9fhejh9ofhghrgohgijgk:\n");
	reset();
	sys = strdup("fkdalhfld;hfla;fhkdjfl;kdjflj49r784570wutkrthj8y(*^*(^&*^&*TY*HU(H&&^*TUIY*(Y*(UYuhfijdhafuh4hf98fhjhg9hrgjdhf9fhejh9ofhghrgohgijgk:\n");
	asem = ft_strdup("fkdalhfld;hfla;fhkdjfl;kdjflj49r784570wutkrthj8y(*^*(^&*^&*TY*HU(H&&^*TUIY*(Y*(UYuhfijdhafuh4hf98fhjhg9hrgjdhf9fhejh9ofhghrgohgijgk:\n");
	printf("[SYS]: [%s]\n", sys);
	printf("[ASM]: [%s]\n", asem);
	free(sys);
	free(asem);
}

void	test_read(void)
{
    int		readfd1;
    int		readfd2;
    int		readfd;
    char	*buf;
	char	*buf3;
	blue();
	printf("*****ft_read*******\n");
	reset();
    buf = calloc(1000, sizeof(char));
	buf3 = calloc(1000, sizeof(char));
	blue();
    printf("\nnormal test\n");
	reset();
    readfd1 = open("ft_read.s", O_RDONLY);
    readfd2 = open("ft_read.s", O_RDONLY);
    readfd = read(readfd1, buf, 4);
    printf("[SYS]: %d\n", readfd);
    readfd = ft_read(readfd2, buf3, 4);
    printf("[ASM]: %d\n", readfd);
	printf("comparing buf and buf2: %i\n", strcmp(buf, buf3));
	free(buf);
	free(buf3);
	blue();
    printf("\nno real text file\n");
	reset();
    readfd = open("empty.txt", O_RDONLY);
	readfd1 = read(readfd, buf, 4);
    readfd2 = ft_read(readfd, buf3, 4);
    printf("[SYS]: %d\n", readfd1);
    printf("[ASM]: %d\n", readfd2);
	blue();
    printf("\nlong text file\n");
	reset();
    readfd = open("notes.txt", O_RDONLY);
    readfd1 = read(readfd, buf, 1000);
    readfd2 = ft_read(readfd, buf3, 1000);
    printf("[SYS]: %d\n", readfd1);
    printf("[ASM]: %d\n", readfd2);
	blue();
    printf("\n\nerrno1\n");
	reset();
    char	buf1[21];
    char	buf2[21];
    int	a = read(333, buf1, 20);
    errno = 100;
    int b = ft_read(333, buf2, 20);
	perror("[SYS] errno");
    perror("[ASM] errno");
	blue();
    printf("\n\nerrno2\n");
	reset();
    printf("[SYS]: %d\n", a);
    printf("[ASM]: %d\n", b);
}

void	test_write(void)
{
	char *sys;
	char *asem;
	int count;
	int fd;
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
	blue();
	printf("\ncheck errno 1:\n");
	reset();
	char	s1[] = "lmao\n";

	int a = write(1, s1, sizeof(s1));
	int	b = ft_write(1, s1, sizeof(s1));
	printf("%i\n%i\n", a, b);
    a = write(FOPEN_MAX + 1, "abcdefghijklmnopqrstuvwxyz\n", 27);
	perror("[SYS]: errno");
	errno = 0;
    b = ft_write(FOPEN_MAX + 1, "abcdefghijklmnopqrstuvwxyz\n", 27);
	perror("[ASM]: errno");
    printf("[SYS]: %d\n[ASM]: %d\n", a, b);
	int	test_fd = OPEN_MAX + 1;
	if (test_fd > 2)
	{
		int c = write(test_fd, "hatsssssss", 8);
		if (c < 0)
			perror("[SYS]: error");
		int d = ft_write(test_fd, "hatsssssss", 8);
		if (d < 0)
			perror("[ASM]: error");
		printf("[SYS]: %d\n[ASM]: %d\n", c, d);
	}
}

void test_all(void)
{
	blue();
	printf("Testing All Functions:\n");
	// strlen
	reset();
	test_strlen();
	printf("\n");

	// strcmp
	test_strcmp();
	printf("\n");
	// strcpy
	test_strcpy();
	printf("\n");
	// strdup
	test_strdup();
	printf("\n");	
	// write
	test_write();
	printf("\n");
	// read
	test_read();
	printf("\n");
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
	{
		print_instructions();
		return (0);
	}
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
		return (0);
	}
	printf("\n start infinite while loop for leaks check:\n");
	while (1)
	{;}
	return (0);
}
