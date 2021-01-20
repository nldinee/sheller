#include "../includes/minishell.h"

int	list_len(t_env *env)
{
	int i;
	i = 0;
	while (env)
	{
		i++;
		env = env->next;
	}
	return (i);
}

void	free_array(char ***arr)
{
	int i;

	i = 0;
	while ((*arr)[i])
		free((*arr)[i++]);
	free((*arr));
	(*arr) = NULL;
}

void	free_env(t_env **env)
{
	t_env		*hlp;

	while (*env)
	{
		hlp = (*env)->next;
		free((*env)->key);
		free((*env)->value);
		free(*env);
		*env = hlp;
	}
	free(*env);
}