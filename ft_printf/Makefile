LIBFT_SRC_FILE	= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
				ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c  ft_memmove.c ft_strlcpy.c \
				ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
				ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_strdup.c ft_calloc.c ft_substr.c \
				ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
				ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putchar_fd.c

LIBFT_SRC		= ${addprefix libft/, ${LIBFT_SRC_FILE}}

LIBFT_OBJS		= ${LIBFT_SRC:.c=.o}

FT_PRINTF_SRC_FILE	= ft_printf.c ft_putnbr_count.c ft_putstr_count.c \
					ft_printf_puthex_small.c ft_printf_puthex_big.c \
					ft_putaddress_count.c ft_putchar_count.c ft_putuint_count.c \

FT_PRINTF_SRC		= ${addprefix srcs/, ${FT_PRINTF_SRC_FILE}}

FT_PRINTF_OBJS		= ${FT_PRINTF_SRC:.c=.o}

OBJS = ${FT_PRINTF_OBJS} ${LIBFT_OBJS}

HEADER		= includes/

NAME		= libftprintf.a

CFLAGS		= -Wall -Wextra -Werror

all:		${NAME}

.c.o:
			cc ${CFLAGS} -c -I ${HEADER} $< -o $@

${NAME}:	${OBJS}
			ar -rcs ${NAME} ${OBJS}

clean:
			rm -f ${OBJS} 

fclean:		clean
			rm -f ${NAME} test

re:			fclean all

program:	re main.c ${NAME}
			cc main.c -L./ -lftprintf -I./${HEADER} -o test

.PHONY:		all clean fclean re program
