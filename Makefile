NAME	= minishell

SRC		= srcs/builtins/builtins.c srcs/builtins/cd.c srcs/builtins/echo.c\
		srcs/builtins/env.c srcs/builtins/exit.c srcs/builtins/setenv.c srcs/builtins/unsetenv.c\
		srcs/env.c srcs/expansion.c srcs/minishell.c srcs/tools.c

OBJ		= $(SRC:.c=.o)

CFLAGS	= 

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