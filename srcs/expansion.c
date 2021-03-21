#include "../includes/minishell.h"



void	handle_telda(char **dlr, t_env *env)
{
	char *tmp;
	char *new;
	int i;
	t_env *e;

	i = 0;
	tmp = *dlr;
	e = get_env(&env, "HOME");
	(e == NULL) ? (e = new_env("HOME", "/Users")) : NULL;
	if (tmp[i++] == '~' && tmp[i] == '/')
	{
		new = ft_strnew( (int)ft_strlen(e->value) + (int)ft_strlen(tmp) + 1);
		ft_bzero(new, (int)ft_strlen(e->value) + (int)ft_strlen(tmp) + 1);
		ft_strcpy(new, e->value);
		ft_strncat(new, &tmp[i], ft_strlen(tmp) - i);
	}
	else if (ft_strcmp(tmp, "~") == 0)
		new = ft_strdup(e->value);
	else
		new = ft_strdup(tmp);
	get_env(&env, "HOME") == NULL ? free_env(&e) : NULL;
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
		while (ft_isascii(tmp[i]))
			i++;
		if (i)
		{
			tmp = ft_strsub(tmp,1, i - 1);
			e = get_env(&env, tmp);
			free(tmp);
			if (e)
			{
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