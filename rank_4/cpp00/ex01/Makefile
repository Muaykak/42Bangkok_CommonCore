
SRC =	main.cpp \
		Contact.cpp

OBJ = ${SRC:.cpp=.o}

CC = c++

C_FLAG = -Wall -Wextra -Werror -std=c++98

INCL = -I./ 

NAME = crappy_phonebook

all: ${NAME}

${NAME}: ${OBJ}
	${CC} ${C_FLAG} ${OBJ} ${INCL} -o ${NAME}

%.o: %.cpp
	${CC} ${C_FLAG} ${INCL} -c $< -o $@

clean:
	rm -rf ${OBJ}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re
