#Directories
SRC_DIR = src/
OBJ_DIR = obj/

MAIN_SRC_DIR = main/

#SRC FILE
MAIN_SRC_FILE = main.c

#FILE
SRC	= ${addprefix ${SRC_DIR}${MAIN_SRC_DIR}, ${MAIN_SRC_FILE}} \

OBJ	= ${patsubst ${SRC_DIR}%.c, ${OBJ_DIR}%.o, ${SRC}}

#Headers
HEADERS = ${wildcard include/*.h}

#Src file dependencies
DEP = ${OBJ:.o=.d}

-include ${DEP}

#Compile Option
CC = cc
FLAG = -Wall -Wextra -Werror -I./include -MMD -MP

#Name
NAME = philo

all : ${NAME}

${NAME}: ${OBJ} Makefile
	@${CC} ${FLAG} ${OBJ} -o ${NAME}
	@echo "build ${NAME} complete"

${OBJ_DIR}:
	@mkdir -p ${OBJ_DIR}

${OBJ_DIR}%.o: ${SRC_DIR}%.c ${HEADERS} | ${OBJ_DIR}
	@mkdir -p ${dir $@}
	@${CC} ${FLAG} -c $< -o $@

clean:
	@rm -f ${OBJ}
	@rm -f ${DEP}
	@echo "Cleaned Project"

fclean: clean
	@rm -f ${NAME}
	@echo "Removed Executable ${NAME}"

re: fclean all

compile_db:
	@echo "generate compilation database"
	@if command -v bear >/dev/null 2>&1; then \
		bear -- ${MAKE} ;\
	else \
		echo "'bear' not found. Falling back to compile_flags.txt"; \
		${MAKE} compile_flags; \
	fi

compile_flags:
	@echo "-I."	> compile_flags.txt
	@echo "-I./include" >> compile_flags.txt
	@echo "-I./src" >> compile_flags.txt
	@echo "Created compile_flags.txt"

.PHONY: clean fclean re all compile_flags

