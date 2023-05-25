CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=thread -g
RM = rm -rf

NAME = philo
SRC = $(shell find . -name "*.c")
OBJ = $(SRC:.c=.o)

# Renkli metinler için değişkenler
GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)Build successful!$(NC)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)Compiled $<$(NC)"

clean:
	@$(RM) $(OBJ)
	@echo "$(GREEN)Cleaned object files!$(NC)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(GREEN)Cleaned executable file!$(NC)"

re: fclean all

.PHONY: all clean fclean re
