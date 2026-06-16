SRC_FILE =	Base.cpp \
			main.cpp

OBJ = ${SRC_FILE:.cpp=.o}

HEADER_FILE =	Base.hpp \
				A.hpp \
				B.hpp \
				C.hpp

CC = c++
CFLAGS = -Wall -Wextra -Werror -pedantic-errors -std=c++98

NAME = indentify

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
