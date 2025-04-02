MAIN_SRC_FILE			=	main.c \

UTILS_SRC_FILE			=	ft_atol.c \
							free_ft_split.c \
							free_numsets.c \
							display_stacks_1.c \
							free_pre_sort_content.c \
							show_pre_sort_num.c \
							display_sorted_stack.c \

CHECK_ARG_SRC_FILE		=	check_format_1.c \
							check_int_limit.c \
							check_duplicate_1.c \
							check_stack_sorted.c \
							check_swapable_1.c \
							check_unsorted.c \

CREATE_STACK_SRC_FILE	=	get_numset_1.c \
							create_stack_a_1.c \
							create_stack_b_1.c \

NODE_FUNCTION_SRC_FILE	=	ps_node_new_1.c \
							ps_node_delone_1.c \
							ps_node_addback_1.c \
							ps_node_clearall_1.c \
							ps_node_addfront_1.c \
							find_node_1.c \
							assign_stack_pos.c \

PUSH_SWAP_OP_SRC_FILE	=	op_sa.c \
							op_sb.c \
							op_pb.c \
							op_pa.c \
							op_ss.c \
							op_ra.c \
							op_rb.c \
							op_rr.c \
							op_rra.c \
							op_rrb.c \
							op_rrr.c \
							easy_rotate_1.c \
							dist_cal_1.c \
							rotate_decider_1.c \

PRE_SORT_SRC_FILE		=	create_pre_sort_stack_1.c \
							pre_quicksort_1.c \
							fill_pre_sort.c \

1ST_ALGOR_SRC_FILE			=	1st_algor_1.c \
								find_closest_to_swap_1.c \
								find_closest_to_push_1.c \

SRC		=	${addprefix ${SRC_DIR}${MAIN_SRC_DIR}, ${MAIN_SRC_FILE}} \
			${addprefix ${SRC_DIR}${UTILS_SRC_DIR}, ${UTILS_SRC_FILE}} \
			${addprefix ${SRC_DIR}${CREATE_STACK_SRC_DIR}, ${CREATE_STACK_SRC_FILE}} \
			${addprefix ${SRC_DIR}${CHECK_ARG_SRC_DIR}, ${CHECK_ARG_SRC_FILE}} \
			${addprefix ${SRC_DIR}${NODE_FUNCTION_SRC_DIR}, ${NODE_FUNCTION_SRC_FILE}} \
			${addprefix ${SRC_DIR}${PUSH_SWAP_OP_SRC_DIR}, ${PUSH_SWAP_OP_SRC_FILE}} \
			${addprefix ${SRC_DIR}${PRE_SORT_SRC_DIR}, ${PRE_SORT_SRC_FILE}} \
			${addprefix ${SRC_DIR}${1ST_ALGOR_SRC_DIR}, ${1ST_ALGOR_SRC_FILE}} \


OBJ			= 	${patsubst ${SRC_DIR}%.c, ${OBJ_DIR}%.o, ${SRC}}

#Directories

1ST_ALGOR_SRC_DIR = 1st_algorithm/

PRE_SORT_SRC_DIR = pre_sort/

PUSH_SWAP_OP_SRC_DIR = push_swap_operation/

NODE_FUNCTION_SRC_DIR = node_function/

MAIN_SRC_DIR		= main/

UTILS_SRC_DIR		= utils/

CREATE_STACK_SRC_DIR	= create_stack/

CHECK_ARG_SRC_DIR	= check/

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
