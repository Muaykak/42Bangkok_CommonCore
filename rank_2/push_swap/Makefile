SRCS_FILE = ft_printf.c ft_printf_putchar_count.c ft_printf_putstr_count.c \
	ft_printf_putnbr_count.c ft_printf_putuint_count.c ft_printf_putaddress_count.c \
	ft_printf_puthex_big_count.c ft_printf_puthex_small_count.c \
	ft_lstlast.c ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
	ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstsize.c ft_lstnew.c \
	ft_atol.c ft_push_swap_utils_1.c ft_split.c ft_strlen.c \
	put_argument.c push_swap_operation_1.c ft_strncmp.c push_swap_operation_2.c \
	push_swap_operation_3.c main_checker.c 

SRC = ${SRCS_FILE}

OBJS = ${SRC:.c=.o}

HEADER = ./

NAME = push_swap

all: ${NAME}

.c.o:
	cc -Wall -Wextra -Werror -c -I${HEADER} $< -o $@

${NAME}: ${OBJS}
	cc -Wall -Wextra -Werror ${OBJS} -o ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME} 

re: fclean all

program:	re main.c ${NAME}
			cc main.c -L./ -lftprintf -I./${HEADER} -o test

.PHONY:		all clean fclean re program
