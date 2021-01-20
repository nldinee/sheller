#include "../../includes/minishell.h"

void ft_env(t_env *env)
{
	while (env)
	{
		ft_putstr(env->key);
		ft_putchar('=');
		ft_putstr(env->value);
		ft_putchar('\n');
		env = env->next;
	}
}
