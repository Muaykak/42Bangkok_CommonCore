# CPP01 Makefile Compilation

# the source files target to compile the program
SRC_FILE = main.cpp Zombie.cpp zombieHorde.cpp

# object  target before compiling to the program
OBJ = ${SRC_FILE:.cpp=.o}

# Header file target
HEADER_FILE = Zombie.hpp
HEADER_DIR = ./

# Name of the program
NAME = ZombieTest

#Compiler and flags
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

all: ${NAME}

${NAME}: ${OBJ}
	${CC} ${FLAGS} ${OBJ} -I${HEADER_DIR} -o ${NAME}

%.o:%.cpp ${HEADER_FILE} Makefile
	${CC} ${FLAGS} -c $< -o $@

clean:
	rm -rf ${NAME}

fclean: clean
	rm -rf ${OBJ}

re: fclean all

.PHONY: all clean fclean re

# Note: C++ can use both .h and .hpp
# Actually the file extension is not important in C or C++
# To **C PREPROCESSOR** the #include simply means "copy the text from that file and paste it right here"