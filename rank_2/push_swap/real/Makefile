SRC_FILE = main_push_swap.c ft_atol.c ft_push_swap_utils1_1.c \
	ft_push_swap_utils1_2.c put_argument_1.c put_argument_2.c \
	push_swap_operation_1.c push_swap_operation_2.c push_swap_stack_check.c \
	push_swap_easy_op_1.c push_swap_easy_op_2.c push_swap_easy_op_3.c \
	push_swap_operation_3.c push_swap_forth_algor_1.c \
	push_swap_forth_algor_2.c ft_push_swap_utils2_1.c \
	ft_push_swap_utils2_2.c push_swap_6th.c

SRC	= ${addprefix ${SRC_DIR},${SRC_FILE}}

OBJS= ${addprefix ${OBJ_DIR},${SRC_FILE:.c=.o}}

SRC_DIR		= src/

OBJ_DIR		= obj/

HEADER = ./include/

LIBFT_DIR = libft/

NAME = push_swap

all: ${LIBFT_DIR}libft.a ${NAME}

${LIBFT_DIR}libft.a:
	make -C ${LIBFT_DIR}

${OBJ_DIR}%.o:${SRC_DIR}%.c

	cc -Wall -Wextra -Werror -c -I${HEADER} $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	cc -Wall -Wextra -Werror $(OBJS) -o $(NAME) -L$(LIBFT_DIR) -lft

clean:
	rm -f ${OBJS} && make fclean -C ${LIBFT_DIR}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY:		all clean fclean re program
