PRINTF_SRC= ft_printf.c ft_putaddress_count.c ft_putchar_count.c \
			ft_puthex_big_count.c ft_puthex_small_count.c \
			ft_putnbr_count.c ft_putstr_count.c ft_putuint_count.c

SRC= ft_atoi.c ft_minitalk_utils_1.c

PRINTF_OBJ= ${PRINTF_SRC:.c=.o}

OBJ= ${SRC:.c.o}

HEADER= 

NAME= program

.c.o:
	cc -Wall -Wextra -Werror -c -I./ $< -o $@

${NAME}: ${PRINTF_OBJ}
	cc -Wall -Wextra -Werror client_main.c ${SRC} ${PRINTF_OBJ} -o client
	cc -Wall -Wextra -Werror server_main.c ${SRC} ${PRINTF_OBJ} -o server

clean:
	rm -f ${OBJ} ${PRINTF_OBJ}

fclean: clean
	rm -f ${NAME} client server

re: fclean all

.PHONY:		all clean fclean re 
