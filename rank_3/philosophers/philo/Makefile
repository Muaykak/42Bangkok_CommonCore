#Directories
SRC_DIR = src/
OBJ_DIR = obj/

MAIN_SRC_DIR = main/
UTILS_SRC_DIR = utils/
PARSER_SRC_DIR = parser/
PHILO_THREAD_DIR = philo_thread/
GETTIME_SRC_DIR = gettime/
PHILO_ROUTINE_SRC_DIR = philo_routine/

#SRC FILE
MAIN_SRC_FILE =		main.c

PARSER_SRC_FILE =	get_philo_args_1.c \
					get_philo_info_1.c \
					ft_check_strnum.c \
					ft_check_digits.c

UTILS_SRC_FILE =	exact_delay.c \
					ft_isspace.c \
					ft_putstr_fd.c \
					ft_strlen.c \
					ft_atollu.c \
					ft_putnbr_fd.c

PHILO_THREAD_FILE =	create_philo_thread_1.c \
					create_philo_fork.c \
					free_philo_array.c

PHILO_ROUTINE_SRC_FILE =	routine_odd_1.c \
							put_routine_1.c \
							philo_lock_1.c \
							philo_unlock_1.c

GETTIME_SRC_FILE =	print_timestamp_1.c \
					convert_timedate_1.c

#FILE
SRC	=	${addprefix ${SRC_DIR}${MAIN_SRC_DIR}, ${MAIN_SRC_FILE}} \
		${addprefix ${SRC_DIR}${UTILS_SRC_DIR}, ${UTILS_SRC_FILE}} \
		${addprefix ${SRC_DIR}${PARSER_SRC_DIR}, ${PARSER_SRC_FILE}} \
		${addprefix ${SRC_DIR}${PHILO_THREAD_DIR}, ${PHILO_THREAD_FILE}} \
		${addprefix ${SRC_DIR}${PHILO_ROUTINE_SRC_DIR}, ${PHILO_ROUTINE_SRC_FILE}} \
		${addprefix ${SRC_DIR}${GETTIME_SRC_DIR}, ${GETTIME_SRC_FILE}}


OBJ	= ${patsubst ${SRC_DIR}%.c, ${OBJ_DIR}%.o, ${SRC}}

#Headers
HEADERS = ${wildcard include/*.h}

#Src file dependencies
DEP = ${OBJ:.o=.d}


#Compile Option
CC = cc
FLAG = -Wall -Wextra -pthread -Werror -I./include -MMD -MP

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

asan: ${OBJ} Makefile
	@clang ${FLAG} -g3 -O0 -fsanitize=address ${OBJ} -o ${NAME}

tsan: ${OBJ} Makefile
	@clang ${FLAG} -g3 -O0 -fsanitize=thread ${OBJ} -o ${NAME}

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

-include ${DEP}

.PHONY: clean fclean re all compile_flags asan tsan

