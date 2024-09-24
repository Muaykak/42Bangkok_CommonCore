SRCS_FILE = ft_printf.c ft_putchar_count.c ft_putstr_count.c \
			ft_putnbr_count.c ft_putuint_count.c ft_putaddress_count.c \
			ft_puthex_big_count.c ft_puthex_small_count.c

SRC = ${addprefix srcs/,${SRCS_FILE}}

OBJS = ${SRC:.c=.o}

HEADER = includes/

NAME = libftprintf.a

all: ${NAME}

.c.o:
	cc -Wall -Wextra -Werror -c -I./${HEADER} $< -o $@

${NAME}: ${OBJS}
	ar -rcs ${NAME} ${OBJS} 

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME} test

re: fclean all

program:	re main.c ${NAME}
			cc main.c -L./ -lftprintf -I./${HEADER} -o test

.PHONY:		all clean fclean re program
