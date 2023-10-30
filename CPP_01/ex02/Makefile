NAME = brain

FLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++

all: $(NAME)
	@echo > /dev/null

$(NAME): main.cpp Makefile
	@$(CC) $(FLAGS) main.cpp -o $(NAME)

clean:
	@if [ -e $(NAME) ]; then \
		rm -rf $(NAME); \
		echo "$(NAME) was deleted!"; \
	fi

fclean: clean

re:	fclean all

.PHONY: all clean fclean re