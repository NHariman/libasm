# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nhariman <nhariman@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/10/09 00:43:23 by nhariman      #+#    #+#                  #
#    Updated: 2020/10/23 11:56:31 by nhariman      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

COMPILE = gcc

FLAGS = -Wall -Werror -Wextra

NASM =	ft_read.s \
		ft_strcmp.s \
		ft_strcpy.s \
		ft_strdup.s \
		ft_strlen.s \
		ft_write.s

ONASM = 	$(NASM:.s=.o)

NAME = libasm.a

all: $(NAME)

$(NAME): $(ONASM)
	ar rcs $@ $^
	$(COMPILE) $(FLAGS) -L. -lasm main.c -o asm_tester

%.o: %.s
	nasm -fmacho64 $< -o $@

clean:
	@$(RM) $(ONASM) asm_tester

fclean: clean
	@$(RM) $(NAME)

re: fclean all

bonus:
	@echo "sorry nothing here"

main: re
	$(COMPILE) $(FLAGS) -L. -lasm main.c -o asm_tester
