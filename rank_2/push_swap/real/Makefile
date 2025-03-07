SRCS_FILE = ft_printf.c ft_printf_putchar_count.c ft_printf_putstr_count.c \
	ft_printf_putnbr_count.c ft_printf_putuint_count.c ft_printf_putaddress_count.c \
	ft_printf_puthex_big_count.c ft_printf_puthex_small_count.c \
	ft_lstlast.c ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
	ft_lstdelone.c ft_lstsize.c ft_lstnew.c ft_atol.c ft_push_swap_utils1_1.c \
	ft_push_swap_utils1_2.c ft_split.c ft_strlen.c \
	put_argument_1.c put_argument_2.c push_swap_operation_1.c \
	ft_strncmp.c push_swap_operation_2.c push_swap_stack_check.c \
	push_swap_easy_op_1.c push_swap_easy_op_2.c push_swap_easy_op_3.c \
	push_swap_operation_3.c push_swap_forth_algor_1.c \
	push_swap_forth_algor_2.c ft_push_swap_utils2_1.c ft_push_swap_utils2_2.c

SRC = ${SRCS_FILE}

OBJS = ${SRC:.c=.o}

MAIN_PUSH_SWAP = main_push_swap.c

MAIN_PUSH_SWAP_OBJ = ${MAIN_PUSH_SWAP:.c=.o}

HEADER = ./

NAME = push_swap

all: ${NAME}

.c.o:
	cc -Wall -Wextra -Werror -c -I${HEADER} $< -o $@

${NAME}: ${OBJS} ${MAIN_PUSH_SWAP_OBJ}
	cc -Wall -Wextra -Werror ${MAIN_PUSH_SWAP_OBJ} ${OBJS} -o ${NAME}

clean:
	rm -f ${OBJS} ${MAIN_CHECKER_OBJ} ${MAIN_PUSH_SWAP_OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY:		all clean fclean re program
