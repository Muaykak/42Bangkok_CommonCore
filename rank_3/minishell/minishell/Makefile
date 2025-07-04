#---------- SRC DIR -------------------------------------------------------

SRC_DIR		=	srcs/
SRC_FILE	=	${addprefix ${SRC_DIR}${MAIN_SRC_DIR}, ${MAIN_SRC_FILE}} \
				${addprefix ${SRC_DIR}${BUILTIN_SRC_DIR}, ${BUILTIN_SRC_FILE}} \
				${addprefix ${SRC_DIR}${ENV_SRC_DIR}, ${ENV_SRC_FILE}} \
				${addprefix ${SRC_DIR}${EXIT_SRC_DIR}, ${EXIT_SRC_FILE}} \
				${addprefix ${SRC_DIR}${PARSER_SRC_DIR}, ${PARSER_SRC_FILE}} \
				${addprefix ${SRC_DIR}${PROCESS_SRC_DIR}, ${PROCESS_SRC_FILE}} \
				${addprefix ${SRC_DIR}${EXEC_SRC_DIR}, ${EXEC_SRC_FILE}} \
				${addprefix ${SRC_DIR}${SIGNAL_SRC_DIR}, ${SIGNAL_SRC_FILE}} \
				${addprefix ${SRC_DIR}${STATIC_VAR_DIR}, ${STATIC_VAR_SRC_FILE}}

OBJ_DIR		=	obj/
OBJ			= 	${patsubst ${SRC_DIR}%.c, ${OBJ_DIR}%.o, ${SRC_FILE}}

MAIN_SRC_DIR	=	main/
BUILTIN_SRC_DIR	=	builtin/
ENV_SRC_DIR		=	env/
EXIT_SRC_DIR	=	exit/
PARSER_SRC_DIR	=	parser/
PROCESS_SRC_DIR	=	process/
EXEC_SRC_DIR	=	${addprefix ${PROCESS_SRC_DIR}, exec/}
SIGNAL_SRC_DIR	=	signals/
STATIC_VAR_DIR	=	static_variables/

#------------------------------------------------------------------------------
########################################################################
############          SRC_FILE	########################################

MAIN_SRC_FILE	=		main.c

BUILTIN_SRC_FILE	=	ft_chdir_1.c ft_chdir_util.c \
						builtin.c ft_echo.c ft_pwd.c ft_env.c \
						ft_export.c ft_unset.c ft_exit_1.c ft_exit_2.c 

ENV_SRC_FILE	=	add_env_list_1.c del_env_list_1.c \
					env_initialize_1.c env_list_utils_1.c \
					ft_split_keyvalue.c get_env_value_1.c \
					print_env.c search_env_1.c set_env_array_1.c \
					set_essential_env_1.c

EXIT_SRC_FILE	=		exit.c

PARSER_SRC_FILE	=		parser_1.c \
						split_newline_1.c \
						lexer_1.c lexer_2.c \
						t_word_struct_utility_1.c t_word_struct_utility_2.c \
						grammar_check_1.c grammar_check_2.c \
						word_expand_1.c word_expand_2.c word_expand_3.c \
						expand_dollar_sign_1.c expand_dollar_sign_2.c \
						remove_quotation_1.c remove_quotation_2.c \
						get_new_cmd_1.c get_redirect_list_1.c \
						make_process_table_1.c \
						cat_all_catlist_1.c \
						remove_empty_expand_1.c \

PROCESS_SRC_FILE	=	heredoc_1.c heredoc_2.c heredoc_3.c \
						redirect.c clear.c \
						process_1.c process_2.c \
						is_directory.c

EXEC_SRC_FILE	=		exec_v2_1.c exec_v2_2.c

SIGNAL_SRC_FILE	=		set_default_signal_1.c set_default_signal_2.c

STATIC_VAR_SRC_FILE	=	env_static.c exit_static.c \
						parser_static.c process_static.c \
						signal_static.c

#----------------------------------------------------------------------------
#############################################################################
#############################################################################
#------- HEADER FILES --------------------

HEADER	=	${MINISHELL_HEADER} ${LIBFT_HEADER}
MINISHELL_HEADER_DIR	=	include/
MINISHELL_HEADER	=	${MINISHELL_HEADER_DIR}minishell.h

#-------	LIBFT ------------------------

LIBFT_DIR	=	libft/

LIBFT_FILE	=	${LIBFT_DIR}/libft.a
LIBFT_HEADER_DIR	=	${LIBFT_DIR}include/
LIBFT_HEADER	=	${LIBFT_HEADER_DIR}libft.h

#-------- COMPILE OPTIONS -------------------------

NAME	=	minishell

CFLAGS	= -Wall -Wextra -Werror
INCLUDE = -I ${MINISHELL_HEADER_DIR} -I ${LIBFT_HEADER_DIR}
LINK	= -L${LIBFT_DIR} -lft -lreadline
CC		= cc

################################################################################

#----- RULE ----------------------------------------

all: ${NAME}

${NAME}: ${LIBFT_FILE} ${OBJ}
		@${CC} ${CFLAGS} ${INCLUDE} ${OBJ} ${LINK} -o ${NAME}
		@echo BUILT $@

${OBJ_DIR}:
		@mkdir -p ${OBJ_DIR}

${LIBFT_FILE}:
		@make -C ${LIBFT_DIR}

${OBJ_DIR}%.o: ${SRC_DIR}%.c ${HEADER} | ${OBJ_DIR}
		@mkdir -p ${dir $@}
		@${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@
		@echo Built $@

clean:
	@rm -rf ${OBJ_DIR}
	@make clean -C $(LIBFT_DIR)
	@echo remove all object files

fclean: clean
	@rm -f ${NAME}
	@make fclean -C ${LIBFT_DIR}
	@echo fclean success.

re:	fclean all

memcheck: all
	valgrind --track-fds=yes --leak-check=full --show-leak-kinds=all ./${NAME}

.PHONY:	all clean fclean re memcheck

# VALGRIND SUPRESSION
#  --- put this flag --suppressions=readline.supp
# readline.supp
#{
#    leak readline
#    Memcheck:Leak
#    ...
#    fun:readline
#}
#{
#    leak add_history
#    Memcheck:Leak
#    ...
#    fun:add_history
#}
# 
