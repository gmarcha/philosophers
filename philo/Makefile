NAME		=	philo
CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror
INC			=	-I ./inc
OBJ			=	$(patsubst src%, obj%, $(SRC:.c=.o))
SRC			=	src/input/input_parse.c \
				src/input/input_read.c \
				src/philo/philo_death.c \
				src/philo/philo_routine.c \
				src/philosophers.c \
				src/utils.c
CLR			=	"\\033[2K"

all:		obj $(NAME)

test:		all
			./philo

$(NAME):	$(OBJ)
			@echo "$(CLR)$(NAME): compilation done"
			@echo "$(NAME): linking object files\r\c"
			@$(CC) $(CFLAGS) -fsanitize=address -o $@ $^ $(LIB)
			@echo "$(CLR)$(NAME): link done"

obj/%.o:	src/%.c
			@echo "$(CLR)$(NAME): compiling $<\r\c"
			@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

obj:
			@mkdir -p obj
			@mkdir -p obj/input
			@mkdir -p obj/philo
			@mkdir -p obj/pthread

clean:
			@rm -rf $(OBJ) obj
			@echo "clean: object files removed"

fclean:		clean
			@rm -rf $(NAME)
			@echo "fclean: binary file removed"

re:			fclean all

.PHONY:		all obj clean fclean re

