SRC_FILE =	ScalarConverter.cpp \
			main.cpp

OBJ = ${SRC_FILE:.cpp=.o}

HEADER_FILE = ScalarConverter.hpp

CC = c++
CFLAGS = -Wall -Wextra -Werror -pedantic-errors -std=c++98

NAME = scalarConverter

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
