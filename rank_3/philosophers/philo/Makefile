# FILE PATH SECITON #################################################################

# DIRECTORIES

SRC_DIR = srcs/
OBJ_DIR = obj/
OBJ		=	${patsubst ${SRC_DIR}%.c, ${OBJ_DIR}%.o, ${SRC_FILE}}

SRC_FILE	=	${addprefix ${SRC_DIR}${MAIN_SRC_DIR}, ${MAIN_SRC_FILE}} \
				${addprefix ${SRC_DIR}${PARSER_SRC_DIR}, ${PARSER_SRC_FILE}} \
				${addprefix ${SRC_DIR}${INIT_SRC_DIR}, ${INIT_SRC_FILE}} \
				${addprefix ${SRC_DIR}${THREAD_MANAGE_SRC_DIR}, ${THREAD_MANAGE_SRC_FILE}} \
				${addprefix ${SRC_DIR}${PHILO_ROUTINE_SRC_DIR}, ${PHILO_ROUTINE_SRC_FILE}} \
				${addprefix ${SRC_DIR}${UTILS_SRC_DIR}, ${UTILS_SRC_FILE}}


#------  SRC_FILE -------#

MAIN_SRC_DIR	=	
MAIN_SRC_FILE	=	main.c

PARSER_SRC_DIR	=	parser/
PARSER_SRC_FILE	=	parser.c

PHILO_ROUTINE_SRC_DIR	=	philo_routine/
PHILO_ROUTINE_SRC_FILE	=	philo_routine.c philo_eat.c philo_sleep.c print_log.c

THREAD_MANAGE_SRC_DIR	=	thread_manage/
THREAD_MANAGE_SRC_FILE	=	create_all_philo.c get_status.c \
							philo_simulation.c set_status.c

INIT_SRC_DIR	=	init/
INIT_SRC_FILE	=	philo_info_init.c philo_thread_init.c

UTILS_SRC_DIR	=	utils/
UTILS_SRC_FILE	=	ft_putstr_fd.c ft_strlen.c ft_isspace.c  ft_philo_atoi.c \
					ft_isdigit.c ft_putnbr_fd.c \
					free_philo_info.c ft_philo_wait.c

#-------  HEADER --------#

PHILO_HEADER_DIR	=	include/
PHILO_HEADER_NAME	=	philo.h
PHILO_HEADER		=	${PHILO_HEADER_DIR}${PHILO_HEADER_NAME}

#####################################################################################

#--------- COMPILE OPTIONS ------#

NAME	= philo

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
LIB		= -lpthread
INCLUDE	= -I ${PHILO_HEADER_DIR}

#####################################################################################

#--------- RULES -------------------

all: ${NAME}

${NAME}: ${OBJ} ${PHILO_HEADER}
	@${CC} ${CFLAGS} ${OBJ} ${INCLUDE} ${LIB} -o ${NAME}
	@echo built ${NAME}

${OBJ_DIR}:
	@mkdir -p ${OBJ_DIR}

${OBJ_DIR}%.o: ${SRC_DIR}%.c ${PHILO_HEADER} Makefile | ${OBJ_DIR}
	@mkdir -p ${dir $@}
	@${CC} ${CFLAGS} -c $< ${INCLUDE} -o $@
	@echo built object $@

clean:
	@rm -rf clean ${OBJ}

fclean: clean
	@rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
