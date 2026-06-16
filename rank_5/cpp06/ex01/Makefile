SRC_FILE =	Serializer.cpp \
			Data.cpp \
			main.cpp

OBJ = ${SRC_FILE:.cpp=.o}

HEADER_FILE =	Serializer.hpp \
				Data.hpp

CC = c++
CFLAGS = -Wall -Wextra -Werror -pedantic-errors -std=c++98

NAME = serializer

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
