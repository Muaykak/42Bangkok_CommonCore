#src_file
MAIN_SRC_FILE	= main.c 

SRC	=	${addprefix ${SRC_DIR}${MAIN_SRC_DIR}, ${MAIN_SRC_FILE}} 
OBJ	=	${patsubst ${SRC_DIR}%.c, ${OBJ_DIR}%.o, ${SRC}} 

#Headers and .o dependencies
HEADERS	= ${wildcard include/*.h}
DEP	= ${OBJ:.o=.d}
-include ${DEP}

#Directories
MAIN_SRC_DIR	= main/
SRC_DIR	= src/
OBJ_DIR	= obj/

#LIBFT
LFT_DIR	= libft/
LIBFT	= ${LFT_DIR}libft.a

#NAME
NAME	= pipex

#COMPILE OPTION
CC		= cc
FLAG	= -Wall -Wextra -Werror -I./include/ -MMD -MP
LINK	= -L${LFT_DIR} -lft
#################################################

##################### RULES #####################

all: ${NAME}

${NAME}: ${OBJ} ${LIBFT} Makefile
	@${CC} ${FLAG} ${OBJ} ${LINK} -o ${NAME}

${OBJ_DIR}:
	@mkdir -p ${OBJ_DIR}

${OBJ_DIR}%.o: ${SRC_DIR}%.c ${HEADERS} | ${OBJ_DIR}
	@mkdir -p ${dir $@}
	@${CC} ${FLAG} -c $< -o $@

${LIBFT}:
	@echo "BUILDING LIBFT"
	@make -C ${LFT_DIR}
	@echo "Built LIBFT SUCCESS"

clean:
	@rm -f ${DEP}
	@rm -f ${OBJ}
	@make fclean -C ${LFT_DIR}
	@echo "cleaned project"

fclean: clean
	@rm -f ${NAME}
	@echo "remove executable ${NAME}"

re: fclean all

.PHONY: clean fclean re all


