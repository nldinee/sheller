#include "../includes/minishell.h"



void	handle_telda(char **dlr, t_env *env)
{
	char *tmp;
	char *new;
	int i;
	t_env *e;

	i = 0;
	tmp = *dlr;
	if (tmp[i++] == '~' && tmp[i] == '/')
	{
		e = get_env(&env, "HOME");
		new = ft_strnew( (int)ft_strlen(e->value) + (int)ft_strlen(tmp) + 1);
		ft_bzero(new, (int)ft_strlen(e->value) + (int)ft_strlen(tmp) + 1);
		ft_strcpy(new, e->value);
		ft_strncat(new, &tmp[i], ft_strlen(tmp) - i);
	}
	else if (ft_strcmp(tmp, "~") == 0)
		new = ft_strdup(get_env(&env, "HOME")->value);
	else
		new = ft_strdup(tmp);
	free(tmp);
	*dlr = new;
}

void	handle_dollar(char **dlr, t_env *env)
{
	int i;
	char *tmp;
	t_env *e;

	tmp = *dlr;
	i = 0;
	if (tmp[i++] == '$')
	{
		while (ft_isalnum(tmp[i]))
			i++;
		if (i)
		{
			tmp = ft_strsub(tmp,1, i - 1);
			e = get_env(&env, tmp);
			if (e)
			{
				free(tmp);
				*dlr = ft_strdup(e->value);
			}
		}
	}
}

int		handle_exp(char **cmd, t_env **env)
{
	int i;
	int j;

	i = 0;
	while (cmd[i])
	{
		handle_dollar(&cmd[i], *env);
		handle_telda(&cmd[i], *env);
		i++;
	}
}