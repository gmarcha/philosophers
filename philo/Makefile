NAME		=	philo
CC			=	clang
FLAGS		=	-Wall -Wextra -Werror
INC			=	-I ./inc
OBJ			=	$(patsubst src%, obj%, $(SRC:.c=.o))
SRC			=	src/destroy_fd.c \
				src/destroy.c \
				src/die.c \
				src/execute.c \
				src/expanse.c \
				src/launch.c \
				src/parsing.c \
				src/pipex.c \
				src/transform.c \
				src/unix_functions.c

all:		obj $(NAME)


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

