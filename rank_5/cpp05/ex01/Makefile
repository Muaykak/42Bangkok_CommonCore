


SRC =	Bureaucrat.cpp \
		Form.cpp \
		main.cpp

OBJ = ${SRC:.cpp=.o}

CFLAGS = -std=c++98 -pedantic-errors -Wall -Wextra -Werror

CC = c++

NAME = program

all: ${NAME}

${NAME}: ${OBJ}
	${CC} ${CFLAGS} -I./ ${OBJ} -o $@

%.o: %.cpp Makefile Bureaucrat.hpp Form.hpp
	${CC} ${CFLAGS} -I./ -c $< -o $@

clean:
	rm -rf ${OBJ}

fclean: clean
	rm -rf ${NAME}

re:	fclean all

.PHONY: all clean fclean re


