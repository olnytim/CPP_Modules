NAME = megaphone

FLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++

all: $(NAME)
	@echo > /dev/null

$(NAME): megaphone.cpp Makefile
	@$(CC) $(FLAGS) megaphone.cpp -o $(NAME)

clean:
	@if [ -e $(NAME) ]; then \
		rm -rf $(NAME); \
		echo "$(NAME) was deleted!"; \
	fi

fclean: clean

re:	fclean all

.PHONY: all clean fclean re