NAME = megaphone

FLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++

PREF_OBJ = obj
SRC = main.cpp Contact.cpp PhoneBook.cpp
OBJ = $(patsubst %.c, $(PREF_OBJ)/%.o, $(SRC))
HEADER = $(wildcard *.hpp)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER) Makefile
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)

$(PREF_OBJ)/%.o: %.cpp %(HEADER) Makefile
	@mkdir -p $(PREF_OBJ)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(PREF_OBJ)

fclean: clean
	@rm -rf $(NAME)

re:	fclean all

.PHONY: all clean fclean re