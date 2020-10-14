# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ybakker <ybakker@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2020/07/15 13:21:09 by ybakker       #+#    #+#                  #
#    Updated: 2020/10/12 12:25:31 by ybakker       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

FLAGS = -Wall -Werror -Wextra
ifdef DEBUG
 FLAGS += -g -fsanitize=address
endif

SRC =	ft_strlen.s \
		ft_strcpy.s \
		ft_strcmp.s \
		ft_strdup.s \
		ft_write.s \
		ft_read.s \

OBJ = $(SRC:%.s=%.o)

all: $(NAME)

%.o : %.s
	nasm -fmacho64 $< -o $@

$(NAME): $(SRC)
	ar -rcs $@ $^

clean:
	rm -rf $(SRC)

fclean: clean
	rm -rf $(OBJ)

re: fclean all

test: re
	gcc -L . -lasm main.c -o test
	./test

test2: re
	gcc -L . -lasm main_mine.c -o test
	./test

test3: re
	gcc -L . -lasm main2.c -o test
	./test