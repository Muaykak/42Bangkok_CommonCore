SRC =	main.cpp \
		replace.cpp

OBJ_DIR = obj/
OBJ = ${addprefix ${OBJ_DIR}, ${SRC:.cpp=.o}}

HEADER = replace.hpp

OUTFILE_NAME = my_file

CC = c++
CFLAG = -Wall -Wextra -Werror -std=c++98
INCLUDE = -I./ -DOUTFILE_NAME='"${OUTFILE_NAME}"'

NAME = test


all: ${NAME}

${NAME}: ${OBJ}
	${CC} ${CFLAG} ${INCLUDE} ${OBJ} -o $@

${OBJ_DIR}:
	@mkdir -p $@

${OBJ_DIR}%.o: %.cpp ${HEADER} | ${OBJ_DIR}
	${CC} ${CFLAG} ${INCLUDE} -c $< -o $@

clean:
	rm -rf ${OBJ_DIR} ${OUTFILE_NAME}


fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re
