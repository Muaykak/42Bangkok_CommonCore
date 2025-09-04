SRC_FILE = src/main.cpp \
		   src/Contact.cpp \
		   src/PhoneBook.cpp

OBJ_DIR = obj/

OBJ = $(addprefix $(OBJ_DIR), $(notdir $(SRC_FILE:.cpp=.o)))

CC = c++

C_DEFINE = -DPROGRAM_NAME='"$(NAME)"'

C_FLAG = -Wall -Wextra -Werror -std=c++98 $(C_DEFINE)

INCL = -Iinclude

NAME = happy_phonebook

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	$(CC) $(C_FLAG) $(OBJ) $(INCL) -o $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: src/%.cpp | $(OBJ_DIR)
	$(CC) $(C_FLAG) $(INCL) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re