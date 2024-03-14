NAME = push_swap
CC = cc
STANDARD_FLAGS = -Wall -Wextra -Werror
SRC_DIR = ./src/
SRCS_FILES 		= $(addprefix ${SRC_DIR},\
				main.c				\
				free.c				\
				ft_atoi.c 			\
				ft_sort_int_tab.c 	\
				ft_split.c 			\
				ft_strdup.c 		\
				ft_strlen.c 		\
				ft_strlen2d.c		\
				ft_substr.c 		\
				ft_swap.c 			\
				ft_strcmp.c			\
				little_sort.c		\
				parsing.c 			\
				push.c 				\
				reverse_rotate.c 	\
				rotate.c 			\
				stacks.c 			\
				swap.c 				\
				transform_stack.c)
OBJ_FILES = $(SRCS_FILES:%.c=%.o)

.PHONY: all clean fclean re

all: ${NAME}

$(NAME) : $(OBJ_FILES)
	$(CC) $(STANDARD_FLAGS) -o $(NAME) $(OBJ_FILES)

%.o : $(SRC_DIR)%.c
	$(CC) -o $@ -c $<

clean: clean
	rm -rf $(OBJ_FILES)

fclean: clean
	rm -rf $(NAME)

re: clean all 
