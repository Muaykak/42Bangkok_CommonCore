SRC_FILE =	main.cpp \
			PmergeMe.cpp

OBJ = ${SRC_FILE:.cpp=.o}

HEADER_FILE =	PmergeMe.hpp \

CC = c++
CFLAGS = -pedantic-errors -std=c++98 -Wall -Wextra -Werror

NAME = PmergeMe

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
