NAME = megaphone

FLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++

all: $(NAME)

$(NAME): megaphone.cpp Makefile
	@$(CC) $(FLAGS) megaphone.cpp -o $(NAME)

clean:
	@rm -rf $(NAME)

fclean: clean
	@rm -rf $(NAME)

re:	fclean all

.PHONY: all clean fclean re