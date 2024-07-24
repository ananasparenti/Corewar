##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## for corewar
##

NAME			=		corewar

FLAGS			=		 -Iinclude -L./lib/my -lmy

CFLAGS			=		 -Werror -Iinclude -L./lib/my -lmy

SRC				=		$(wildcard ./src/*.c ./src/instructions/*.c)

OBJ				=		$(SRC:.c=.o)

RM 				=		rm -f

DEBUG			=		-g3 -g

DEL 			=		./tests/unit_tests*		\
						*.gcda					\
						*.gcno					\
						vgcore*					\
						*.html					\
						*.css

%.o:			%.c
				@gcc -c -o $@ $< $(FLAGS)

all:			$(NAME)

libs:
				@make --no-print-directory -C ./lib/my

$(NAME):		libs $(OBJ)
				@gcc -o $(NAME) $(OBJ) $(FLAGS)
				@echo -e "\033[1;36mCompilation done...\033[0m"

debug:			libs $(OBJ)
				@gcc -o $(NAME) $(OBJ) $(FLAGS) $(DEBUG)
				valgrind ./$(NAME)

unit_tests:	    fclean
				@make --no-print-directory -C./tests/ unit_tests
				gcovr --exclude tests/ --branch --html-details tests/unit_tests.html

clean:
				@$(RM) $(OBJ)
				@$(RM) *~

fclean:			clean
				@$(RM) $(NAME)
				@echo -e "\033[1;31m$(NAME) clean...\033[0m"
				@make fclean --no-print-directory -C ./lib/my
				@$(RM) $(DEL)
				@echo -e "\033[1;31mCleaning done...\033[0m"
				@$(RM) unit_tests
				@$(RM) ./tests/printf/*.o
				@$(RM) ./tests/42shell/*.o

re:				fclean all
