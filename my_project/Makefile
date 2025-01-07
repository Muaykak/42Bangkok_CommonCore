LIBFT_SRC	= ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
			  ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c

LIBFT_OBJS	= ${LIBFT_SRC:.c=.o}

GNL_SRC		= get_next_line.c get_next_line_utils.c

GNL_SRC_BONUS = get_next_line_bonus.c get_next_line_utils_bonus.c

GNL_OBJS	= ${GNL_SRC:.c=.o}

GNL_OBJS_BONUS = ${GNL_SRC_BONUS:.c=.o}

MY_SRC	= main.c

MY_OBJS	= ${MY_SRC:.c=.o}

FT_PRINTF_SRCS_FILE = ft_printf.c ft_putchar_count.c ft_putstr_count.c \
			ft_putnbr_count.c ft_putuint_count.c ft_putaddress_count.c \
			ft_puthex_big_count.c ft_puthex_small_count.c

FT_PRINTF_OBJS = ${FT_PRINTF_SRCS_FILE:.c=.o}

CFLAGS	= -Wall -Wextra -Werror

NAME	= program

BONUS_NAME = libgnl_bonus.a

HEADER	= ./

all: ${NAME}

.c.o:
	cc ${CFLAGS} -c $< -I${HEADER} -o $@

${NAME}: ${GNL_OBJS_BONUS} ${MY_OBJS} ${FT_PRINTF_OBJS} ${LIBFT_OBJS}
	cc ${CFLAGS} ${MY_OBJS} ${GNL_OBJS_BONUS} ${FT_PRINTF_OBJS} ${LIBFT_OBJS} -o ${NAME} && make clean

bonus: ${OBJS_BONUS}
	ar -rcs ${NAME} ${OBJS_BONUS}
clean:
	rm -f ${GNL_OBJS} ${GNL_OBJS_BONUS} ${MY_OBJS} ${FT_PRINTF_OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: clean fclean re all program