SRC_DIR = src/
SRC_FILE =	main.cpp \
			Animal.cpp \
			Cat.cpp \
			Dog.cpp \
			WrongCat.cpp \
			WrongAnimal.cpp

SRC = ${addprefix ${SRC_DIR}, ${SRC_FILE}}

OBJ_DIR = obj/
OBJ = ${patsubst ${SRC_DIR}%.cpp, ${OBJ_DIR}%.o, ${SRC}}

CC = c++
CFLAG = -Wall -Wextra -Werror -std=c++98
INCLUDE = -I./include/

HEADER_FILE =	Animal.hpp \
			Cat.hpp \
			Dog.hpp \
			WrongAnimal.hpp \
			WrongCat.hpp 
HEADER = ${addprefix include/, ${HEADER_FILE}}

NAME = program

all: ${NAME}

${NAME}: ${OBJ}
	${CC} ${CFLAG} ${INCLUDE} ${OBJ} -o $@

${OBJ_DIR}:
	@mkdir -p $@

${OBJ_DIR}%.o: ${SRC_DIR}%.cpp ${HEADER} | ${OBJ_DIR}
	${CC} ${CFLAG} ${INCLUDE} -c $< -o $@

clean:
	rm -rf ${OBJ_DIR}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re
