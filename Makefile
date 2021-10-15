CC = cc

CFLAGS = -g -Wall -Wextra -Werror

INCLUDES = ./includes/push_swap.h

NAME = push_swap.a

SOURCES = ./src/push_swap.c ./src/ft_utils_list.c ./src/ft_operations.c ./src/ft_utils.c \
./src/ft_utils_list2.c ./src/ft_sorting.c ./src/ft_array.c ./src/ft_utils_list3.c ./src/a_to_b.c \
./src/b_to_a.c ./src/b_to_a2.c ./src/b_to_a3.c ./src/b_to_a4.c ./src/b_to_a5.c ./src/ft_parse.c ./src/ft_error.c ./src/ft_hardcode.c

SOURCES_BONUS = ./src_bonus/ft_checker.c ./src_bonus/get_next_line.c ./src_bonus/get_next_line_utils.c \
./src_bonus/ft_reading.c ./src_bonus/ft_operations2.c ./src_bonus/ft_check.c ./src_bonus/ft_error2.c \
./src/ft_parse.c ./src/ft_utils.c ./src/ft_error.c ./src/ft_utils_list.c ./src/ft_utils_list2.c \

OBJECTS = $(SOURCES:.c=.o)

OBJECTS_BONUS = $(SOURCES_BONUS:.c=.o)

LIBFT_PATH = ./libft/

all: subsystem $(NAME)

info: header

define HEADER
	                 _
	                | |
	 _ __  _   _ ___| |__    _____      ____ _ _ __
	| '_ \| | | / __| '_ \  / __\ \ /\ / / _` | '_ \\
	| |_) | |_| \__ \ | | | \__ \\ V  V / (_| | |_) |
	| .__/ \__,_|___/_| |_| |___/ \_/\_/ \__,_| .__/
	| |                                       | |
	|_|                                       |_|

endef
export HEADER

header:
	@echo "$$HEADER"

subsystem : header
	make -C ./libft
	cp ./libft/libft.a libft.a

$(NAME): subsystem $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) libft.a -o push_swap

bonus: subsystem $(OBJECTS_BONUS)
	$(CC) $(CFLAGS) $(OBJECTS_BONUS) libft.a -o checker
clean:
	rm -f $(OBJECTS)
	rm -f $(OBJECTS_BONUS)
	rm -f $(LIBFT_PATH)*.o

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT_PATH)libft.a
	rm -f libft.a
	rm -f push_swap
	rm -f checker

re: fclean all