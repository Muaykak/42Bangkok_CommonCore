SRC_FILE =	main.cpp \
			BitcoinExchange.cpp

OBJ = ${SRC_FILE:.cpp=.o}

HEADER_FILE =	BitcoinExchange.hpp \

CC = c++
DATABASE_FILE = ./data.csv
CFLAGS = -pedantic-errors -std=c++98 -Wall -Wextra -Werror -DBITCOIN_EXCHANGE_DATABASE_PATH='"${DATABASE_FILE}"'


NAME = btc

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
