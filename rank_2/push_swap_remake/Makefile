MAIN_SRC_FILE			=	main.c \

UTILS_SRC_FILE			=	ft_atol.c \
							free_ft_split.c \
							free_numsets.c \

CHECK_ARG_SRC_FILE		=	check_format_1.c \
							check_int_limit.c \
							check_duplicate_1.c \

CREATE_STACK_SRC_FILE	=	get_numset_1.c \

SRC		=	${addprefix ${SRC_DIR}${MAIN_SRC_DIR}, ${MAIN_SRC_FILE}} \
			${addprefix ${SRC_DIR}${UTILS_SRC_DIR}, ${UTILS_SRC_FILE}} \
			${addprefix ${SRC_DIR}${CREATE_STACK_SRC_DIR}, ${CREATE_STACK_SRC_FILE}} \
			${addprefix ${SRC_DIR}${CHECK_ARG_SRC_DIR}, ${CHECK_ARG_SRC_FILE}} \

OBJ			= 	${patsubst ${SRC_DIR}%.c, ${OBJ_DIR}%.o, ${SRC}}

#Directories

MAIN_SRC_DIR		= main/

UTILS_SRC_DIR		= utils/

CREATE_STACK_SRC_DIR	= create_stack/

CHECK_ARG_SRC_DIR	= check_argument/

SRC_DIR				= src/

OBJ_DIR				= obj/

LFT_DIR				= libft/

#lib

LIBFT	= ${LFT_DIR}libft.a

#name

NAME	= push_swap

CC		= cc

FLAG	= -Wall -Wextra -Werror

LINK	= -L${LFT_DIR} -lft

all: ${NAME}

${NAME}: ${OBJ} ${LIBFT}
	@${CC} ${FLAG} ${OBJ} ${LINK} -o ${NAME}
	@echo "built ${NAME} complete"

${OBJ_DIR}:
	@mkdir -p ${OBJ_DIR}

${OBJ_DIR}%.o: ${SRC_DIR}%.c | ${OBJ_DIR}
	@mkdir -p $(dir $@)
	@${CC} ${FLAG} -c -I./include/ -I./${LFT_DIR}include/ $< -o $@

${LIBFT}:
	@echo "Building LIBFT"
	@make -C ${LFT_DIR}
	@echo "Built LIBFT SUCCESS"

clean:
	@rm -f ${OBJ}
	@make fclean -C ${LFT_DIR}
	@echo "Cleaned Project."

fclean: clean
	@rm -f ${NAME}
	@echo "remove executable ${NAME}"

re: fclean all

.PHONY: clean fclean re all
