PRINTF_SRC= ft_printf.c ft_putaddress_count.c ft_putchar_count.c \
			ft_puthex_big_count.c ft_puthex_small_count.c \
			ft_putnbr_count.c ft_putstr_count.c ft_putuint_count.c

SRC= main.c

PRINTF_OBJ= ${PRINTF_SRC:.c=.o}

OBJ= ${SRC:.c.o}

HEADER= 

NAME= program

.c.o:
	cc -Wall -Wextra -Werror -c -I./ $< -o $@

${NAME}: ${PRINTF_OBJ}
	cc -Wall -Wextra -Werror ${SRC} ${PRINTF_OBJ} -o ${NAME}

clean:
	rm -f ${OBJ} ${PRINTF_OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY:		all clean fclean re 
