SRC_FILE =	Bureaucrat.cpp \
			PresidentialPardonForm.cpp \
			RobotomyRequestForm.cpp \
			ShrubberyCreationForm.cpp \
			AForm.cpp \
			Intern.cpp \
			main.cpp

OBJ = ${SRC_FILE:.cpp=.o}

HEADER_FILE =	AForm.hpp \
				Bureaucrat.hpp \
				PresidentialPardonForm.hpp \
				RobotomyRequestForm.hpp \
				ShrubberyCreationForm.hpp \
				Intern.hpp

CC = c++
CFLAGS = -std=c++98 -pedantic-errors -Wall -Wextra -Werror
NAME = form_test

all: ${NAME}

${NAME}: ${OBJ}
	${CC} ${CFLAGS} ${OBJ} -I./ -o $@

%.o:%.cpp Makefile ${HEADER_FILE}
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -rf ${OBJ}
	rm -rf ./*_shrubbery # to remove <target>_shurbbery file

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re
