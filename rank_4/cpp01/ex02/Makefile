SRC =	main.cpp

OBJ = ${SRC:.cpp=.o}

CC = c++
CFLAG = -Wall -Wextra -Werror -std=c++98

NAME = Brain

all: ${NAME}

${NAME}: ${OBJ}
	${CC} ${CFLAG} ${OBJ} -o ${NAME}

%.o:%.cpp Makefile
	${CC} ${CFLAG} -c $< -o $@

clean:
	rm -rf ${NAME}

fclean: clean
	rm -rf ${OBJ}

re: fclean all

.PHONY: all clean fclean re