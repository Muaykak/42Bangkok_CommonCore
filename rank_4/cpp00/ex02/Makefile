SRC_FILE = Account.cpp \
			tests.cpp

OBJ_FILE = ${SRC_FILE:.cpp=.o}

CC = c++

C_FLAG = -Wall -Wextra -Werror -std=c++98 -I./

NAME = test

all: ${NAME}

${NAME}: ${OBJ_FILE}
	${CC} ${C_FLAG} ${OBJ_FILE} -o $@

%.o: %.c
	${CC} ${C_FLAG} -c $< -o $@

clean:
	rm -rf ${OBJ_FILE}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re
