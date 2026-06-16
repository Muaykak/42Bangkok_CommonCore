SRC_FILE =	main.cpp \
			Span.cpp

OBJ = ${SRC_FILE:.cpp=.o}

HEADER_FILE =	Span.hpp \

CC = c++
CFLAGS = -Wall -Wextra -Werror -pedantic-errors -std=c++98

NAME = ex01

all: ${NAME}

${NAME}: ${OBJ}
	${CC} ${CFLAGS} ${OBJ} -I./ -o $@

%.o: %.cpp Makefile ${HEADER_FILE}
	${CC} ${CFLAGS} -I./ -c $< -o $@

clean:
	rm -rf ${OBJ}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re
