NAME		=	philo
CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror
INC			=	-I ./inc
OBJ			=	$(patsubst src%, obj%, $(SRC:.c=.o))
SRC			=	src/input/input_parse.c \
				src/input/input_read.c \
				src/philo/philo_death.c \
				src/philo/philo_routine.c \
				src/pthread/pthread_allocate_mutex_threads.c \
				src/pthread/pthread_clear_mutex.c \
				src/pthread/pthread_clear_threads.c \
				src/pthread/pthread_destroy_mutex_threads.c \
				src/pthread/pthread_init_mutex.c \
				src/pthread/pthread_init_threads.c \
				src/utils/ft_aredigits.c \
				src/utils/ft_atol.c \
				src/utils/ft_current_time.c \
				src/utils/ft_sleep.c \
				src/utils/ft_strlen.c \
				src/philosophers.c
CLR			=	"\\033[2K"

all:		obj $(NAME)

test:		all
			./philo 1 800 200 200
			./philo 2
			./philo 4 410 200 200
			./philo 5 800 200 200
			./philo 4 310 200 100
			./philo 5 800 200 200 7

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
			@mkdir -p obj/utils

clean:
			@rm -rf $(OBJ) obj
			@echo "clean: object files removed"

fclean:		clean
			@rm -rf $(NAME)
			@echo "fclean: binary file removed"

re:			fclean all

.PHONY:		all obj clean fclean re

