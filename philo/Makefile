NAME		=	philo
CC			=	clang
FLAGS		=	-Wall -Wextra -Werror
INC			=	-I ./inc
OBJ			=	$(patsubst src%, obj%, $(SRC:.c=.o))
SRC			=	src/input_parse.c \
				src/input_read.c \
				src/philosophers.c \
				src/utils.c

all:		obj $(NAME)

test:		all
			./philo

$(NAME):	$(OBJ)
			$(CC) $(FLAGS) -fsanitize=address -o $@ $^ $(LIB)

obj:
			@mkdir -p obj

obj/%.o:	src/%.c
			$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean:
			@rm -rf $(OBJ) obj
			@echo "clean: object files removed."

fclean:		clean
			@rm -rf $(NAME)
			@echo "fclean: binary files removed."

re:			fclean all

.PHONY:		all clean fclean re

