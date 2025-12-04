
SRC = megaphone.cpp

OBJ = ${SRC:.cpp=.o}

CC = c++

C_FLAG = -Wall -Wextra -Werror -std=c++98

NAME = megaphone

all: ${NAME}

${NAME}: ${OBJ}
	${CC} ${C_FLAG} ${OBJ} -o ${NAME}

${OBJ}: ${SRC}
	${CC} ${C_FLAG} -c $< -o $@

clean:
	rm -rf ${OBJ}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re
