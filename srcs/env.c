#include "../includes/minishell.h"

t_env *new_env(char *key, char *value)
{
	t_env *item;
	item = NULL;
	if (!key || !value)
		return (NULL);
	item = (t_env *)ft_memalloc(sizeof(t_env));
	item->key = ft_strdup(key);
	item->value = ft_strdup(value);
	item->next = NULL;
	return (item);
}

void env_append(t_env **env, t_env *item)
{
	t_env *p;

	if (!env || !item)
		return;
	if (*env == NULL)
		*env = item;
	else
	{
		p = *env;
		while (p->next)
			p = p->next;
		p->next = item;
	}
}

void env_delete(t_env **env, char *key)
{
	t_env *tmp;

	tmp = *env;
	t_env *prev;

	if (tmp != NULL && ft_strcmp(tmp->key,key) == 0)
	{
		*env = tmp->next;
		free(tmp);
		return;
	}
	while (tmp != NULL && ft_strcmp(tmp->key,key) != 0)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (tmp == NULL)
		return;
	prev->next = tmp->next;
	free(tmp);
}

t_env	*get_env(t_env **env,char *key)
{
	t_env *tmp;

	tmp = *env;
	while (tmp)
	{
		if (ft_strcmp(tmp->key, key) == 0)
			return(tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void 	copy_env(t_env **env, char **environ)
{
	char **arr;
	arr = NULL;
	int i;
	i = -1;
	while (environ[++i] != NULL)
	{
		arr = ft_strsplit(environ[i], '=');
		env_append(env, new_env(arr[0], arr[1]));
		free(arr);
	}
}
