PRINTF_SRC= ft_printf.c ft_putaddress_count.c ft_putchar_count.c \
			ft_puthex_big_count.c ft_puthex_small_count.c \
			ft_putnbr_count.c ft_putstr_count.c ft_putuint_count.c

SRC= ft_atoi.c ft_minitalk_utils_1.c

PRINTF_OBJ= ${PRINTF_SRC:.c=.o}

OBJ= ${SRC:.c.o}

CLIENT_MAIN= client_main_1.c client_main_2.c

CLIENT_MAIN_OBJ= ${CLIENT_MAIN:.c=.o}

SERVER_MAIN= server_main.c

SERVER_MAIN_OBJ= ${SERVER_MAIN:.c=.o}

HEADER= 

NAME= minitalk

.c.o:
	cc -Wall -Wextra -Werror -c -I./ $< -o $@

${NAME}: ${PRINTF_OBJ} ${OBJ} ${CLIENT_MAIN_OBJ} ${SERVER_MAIN_OBJ}
	cc -Wall -Wextra -Werror ${CLIENT_MAIN_OBJ} ${SRC} ${PRINTF_OBJ} -o client
	cc -Wall -Wextra -Werror ${SERVER_MAIN_OBJ} ${SRC} ${PRINTF_OBJ} -o server

clean:
	rm -f ${OBJ} ${PRINTF_OBJ} ${CLIENT_MAIN_OBJ} ${SERVER_MAIN_OBJ}

fclean: clean
	rm -f client server

re: fclean all

.PHONY:		all clean fclean re 
