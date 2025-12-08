SRC_DIR = src/
SRC_FILE = main.cpp Animal.cpp Dog.cpp Cat.cpp \
			Brain.cpp

OBJ = ${addprefix ${OBJ_DIR}, ${SRC_FILE:.cpp=.o}}
OBJ_DIR = obj/

HEADER = Animal.hpp Dog.hpp Cat.hpp \
		Brain.hpp

HEADER_DIR = ./include/
HEADER_FILE = ${addprefix ${HEADER_DIR}, ${HEADER}}


CC = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror

NAME = program

all: ${NAME}

${NAME}: ${OBJ}
	${CC} ${FLAGS} ${OBJ} -I${HEADER_DIR} -o $@

${OBJ_DIR}:
	mkdir -p $@

${OBJ_DIR}%.o:${SRC_DIR}%.cpp Makefile ${HEADER_FILE} | ${OBJ_DIR}
	${CC} ${FLAGS} -c $< -o $@

clean:
	rm -rf ${OBJ_DIR}

fclean: clean
	rm -rf ${NAME}

re: fclean all

run: ${NAME}
	clear
	./${NAME}

.PHONY: all clean fclean re