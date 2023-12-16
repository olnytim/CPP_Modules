NAME = converter

FLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++

PREF_OBJ = obj
SRC = main.cpp ScalarConverter.cpp
OBJ = $(patsubst %.cpp, $(PREF_OBJ)/%.o, $(SRC))
HEADER = $(wildcard *.hpp)

all: $(NAME)
	@echo > /dev/null

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "$(NAME) file was created!"


$(PREF_OBJ)/%.o: %.cpp $(HEADER) Makefile
	@mkdir -p $(PREF_OBJ)
	@if [ ! -e $(NAME) ]; then \
		$(CC) $(FLAGS) -c $< -o $@; \
	else \
		$(CC) $(FLAGS) -c $< -o $@; \
		echo "$(SRC) $(HEADER) or Makefile files were updated!"; \
	fi

clean:
	@if [ -d $(PREF_OBJ) ]; then \
		rm -rf $(PREF_OBJ); \
		echo "$(PREF_OBJ) was deleted!"; \
	fi

fclean: clean
	@if [ -e $(NAME) ]; then \
		rm -rf $(NAME); \
		echo "$(NAME) was deleted!"; \
	fi

re:	fclean all

.PHONY: all clean fclean re