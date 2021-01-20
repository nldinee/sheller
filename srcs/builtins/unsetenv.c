#include "../../includes/minishell.h"

void ft_unsetenv(char **cmdargs, t_env **env)
{
	int	i;

	i = 0;
	while (cmdargs[i])
		i++;
	if (i - 1 != 1)
	{
		ft_putendl("Too few, many arguments.");
		return;
	}
	if (get_env(env,cmdargs[1]))
		env_delete(env, cmdargs[1]);
}