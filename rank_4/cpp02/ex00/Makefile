SRC =	main.cpp \
		Fixed.cpp

OBJ_DIR = obj/
OBJ = ${addprefix ${OBJ_DIR}, ${SRC:.cpp=.o}}

CC = c++
CFLAG = -Wall -Wextra -Werror -std=c++98
INCLUDE = -I./

HEADER = Fixed.hpp

NAME = program


all: ${NAME}

${NAME}: ${OBJ}
	${CC} ${CFLAG} ${INCLUDE} ${OBJ} -o $@

${OBJ_DIR}:
	mkdir -p $@

${OBJ_DIR}%.o: %.cpp ${HEADER} | ${OBJ_DIR}
	${CC} ${CFLAG} ${INCLUDE} -c $< -o $@

clean:
	rm -rf ${OBJ_DIR}

fclean: clean
	rm -rf ${NAME}

re: fclean all

run: ${NAME}
	@./${NAME}

.PHONY: all clean fclean re run
