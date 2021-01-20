#include "../../includes/minishell.h"

void		ft_exit(char ***final, t_env **env, char **input)
{
	if (final)
		free_array(final);
	ft_strdel(input);
	free_env(env);
	exit(0);
}