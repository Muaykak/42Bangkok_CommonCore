# FILE PATH SECITON #################################################################

# DIRECTORIES

SRC_DIR = srcs/
OBJ_DIR = obj/
OBJ		=	${patsubst ${SRC_DIR}%.c, ${OBJ_DIR}%.o, ${SRC_FILE}}

SRC_FILE	=	${addprefix ${SRC_DIR}${MAIN_SRC_DIR}, ${MAIN_SRC_FILE}} 

#------  SRC_FILE -------#

MAIN_SRC_DIR	=	
MAIN_SRC_FILE	=	main.c

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
INCLUDE	= -I ${PHILO_HEADER}

#####################################################################################

#--------- RULES -------------------

all: ${NAME}

${NAME}: ${OBJ}
	${CC} ${CFLAGS} ${OBJ} ${INCLUDE} ${LIB} -o ${NAME}

${OBJ_DIR}:
		@mkdir -p ${OBJ_DIR}

${OBJ_DIR}%.o: ${SRC_DIR}%.c ${HEADER} | ${OBJ_DIR}
	@mkdir -p ${dir $@}
	${CC} ${CFLAGS} -c $< ${INCLUDE} -o $@
	@echo built object $@

clean:
	@rm -rf clean ${OBJ}

fclean: clean
	@rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
