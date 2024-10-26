SRC		= get_next_line.c get_next_line_utils.c

SRC_BONUS = get_next_line_bonus.c get_next_line_utils_bonus.c

OBJS	= ${SRC:.c=.o}

OBJS_BONUS = ${SRC_BONUS:.c=.o}

CFLAGS	= -Wall -Wextra -Werror

NAME	= libgnl.a

BONUS_NAME = libgnl_bonus.a

HEADER	= ./

all: ${NAME}

.c.o:
	cc ${CFLAGS} -c $< -I${HEADER} -o $@

${NAME}: ${OBJS}
	ar -rcs ${NAME} ${OBJS}

program: re main.c ${NAME}
	cc main.c -L./ -lgnl -I${HEADER} -o test

bonus: ${OBJS_BONUS}
	ar -rcs ${NAME} ${OBJS_BONUS}
clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME} test

re: fclean all

.PHONY: clean fclean re all program