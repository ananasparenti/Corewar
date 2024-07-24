##
## EPITECH PROJECT, 2024
## makefile
## File description:
## for units tests
##

NAME		=	unit_tests

CFLAGS		=	-Wextra -Wall -Werror -I../include -L../lib/my -lcriterion -lgcov --coverage

SRC			=	$(wildcard ../lib/my/*.c)
SRC			+=	../src/alias.c
SRC			+=	../src/arrow_left.c
SRC			+=	../src/arrow_right.c
SRC			+=	../src/check_redirection.c
SRC			+=	../src/double_arrow_left.c
SRC			+=	../src/double_arrow_right.c
SRC			+=	../src/env.c
SRC			+=	../src/execve.c
SRC			+=	../src/fill_env.c
SRC			+=	../src/free.c
SRC			+=	../src/gather_data_snd.c
SRC			+=	../src/gather_data.c
SRC			+=	../src/my_cd.c
SRC			+=	../src/my_exit.c
SRC			+=	../src/my_list_to_tab.c
SRC			+=	../src/my_memset.c
SRC			+=	../src/pipe.c
SRC			+=	../src/search_if_exist.c
SRC			+=	../src/setenv.c
SRC			+=	../src/str_to_array_count.c
SRC			+=	../src/struct_static.c
SRC			+=	../src/unsetenv.c
SRC			+=	../src/unsetenv_all.c
SRC			+=	../src/repeat.c
SRC			+=	../src/which.c

TEST_SRC	=	$(wildcard ./printf/*.c)

RM 			=	rm -rf

DEL 		=	unit_tests*		\
				*.gcda					\
				*.gcno					\
				vgcore*					\
				*.html					\
				*.css

all:		$(NAME)

$(NAME):	
			@echo -e "\033[1;36mCompilation in progress...\033[0m"
			@gcc -o $(NAME) $(SRC) $(TEST_SRC) $(CFLAGS)
			@echo -e "\033[1;36mCompilation done...\033[0m"
			@cp unit_tests ../unit_tests
			@../unit_tests
			@echo -e "\033[1;36mUnit tests done...\033[0m"

clean:
			@$(RM) *~
			@$(RM) $(DEL)

fclean:		clean
			@$(RM) $(NAME)
			@echo -e "\033[1;31m$(NAME) clean...\033[0m"
			@make fclean --no-print-directory -C ../lib/my
			@echo -e "\033[1;31mCleaning done...\033[0m"

unit_tests:	fclean all
#--exclude tests/ --branches
