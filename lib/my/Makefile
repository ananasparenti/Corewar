##
## EPITECH PROJECT, 2024
## makefile
## File description:
## for my lib
##

NAME	=	libmy.a

SRC		=	$(wildcard *.c)

OBJ		=	$(SRC:.c=.o)

FLAGS	=	-I.

CFLAGS	=	-Wall -Wextra -Werror -I.

%.o:		%.c
			@gcc -c -o $@ $< $(FLAGS)

all:		$(NAME)

$(NAME):	$(OBJ)
			@ar rc $(NAME) $(OBJ)
			@echo -e "\033[1;36mCompilation lib done...\033[0m"

clean:
			@rm -f $(OBJ)

fclean:		clean
			@rm -f $(NAME)
			@echo -e "\033[1;31mLib clean...\033[0m"

re:			fclean all
