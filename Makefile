NAME	= minishell

SRC		= srcs/builtins/builtins.c srcs/builtins/cd.c srcs/builtins/echo.c\
		srcs/builtins/env.c srcs/builtins/exit.c srcs/builtins/setenv.c srcs/builtins/unsetenv.c\
		srcs/env.c srcs/expansions.c srcs/minishell.c srcs/tools.c srcs/cmd.c

OBJ		= $(SRC:.c=.o)

CFLAGS	= -Wall -Werror -Wextra

$(NAME): $(OBJ)
	@make -C libft/
	@gcc $(OBJ) -o $(NAME) -L libft/ -lft

all: $(NAME)

clean:
	@make -C libft/ clean
	@rm -rf $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@rm -rf $(NAME) $(OBJ)

re: fclean $(NAME)