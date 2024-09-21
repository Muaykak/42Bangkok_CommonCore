SRC		= get_next_line.c get_next_line_utils.c

OBJS	= ${SRC:.c=.o}

CFLAGS	= -Wall -Wextra -Werror

NAME	= libgnl.a

HEADER	= ./

all: ${NAME}

.c.o:
	cc ${CFLAGS} -c $< -I${HEADER} -o $@

${NAME}: ${OBJS}
	ar -rcs ${NAME} ${OBJS}

program: re main.c ${NAME}
	cc main.c -L./ -lgnl -I${HEADER} -o test

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME} test

re: fclean all

.PHONY: clean fclean re all program