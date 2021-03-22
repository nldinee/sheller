/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabdelba <nabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 15:15:03 by nabdelba          #+#    #+#             */
/*   Updated: 2021/03/22 15:18:03 by nabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_env		*new_env(char *key, char *value)
{
	t_env	*item;

	item = NULL;
	if (!key || !value)
		return (NULL);
	item = (t_env *)ft_memalloc(sizeof(t_env));
	item->key = ft_strdup(key);
	item->value = ft_strdup(value);
	item->next = NULL;
	return (item);
}

void		env_append(t_env **env, t_env *item)
{
	t_env	*p;

	if (!env || !item)
		return ;
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

void		env_delete(t_env **env, char *key)
{
	t_env	*tmp;
	t_env	*prev;

	tmp = *env;
	if (tmp != NULL && ft_strcmp(tmp->key, key) == 0)
	{
		*env = tmp->next;
		tmp->value ? free(tmp->value) : NULL;
		tmp->key ? free(tmp->key) : NULL;
		free(tmp);
		return ;
	}
	while (tmp != NULL && ft_strcmp(tmp->key, key) != 0)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (tmp == NULL)
		return ;
	prev->next = tmp->next;
	tmp->value ? free(tmp->value) : NULL;
	tmp->key ? free(tmp->key) : NULL;
	free(tmp);
}

t_env		*get_env(t_env **env, char *key)
{
	t_env	*tmp;

	tmp = *env;
	while (tmp)
	{
		if (ft_strcmp(tmp->key, key) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void		copy_env(t_env **env, char **environ)
{
	char	**arr;
	int		i;

	arr = NULL;
	i = -1;
	while (environ[++i] != NULL)
	{
		arr = ft_strsplit(environ[i], '=');
		env_append(env, new_env(arr[0], arr[1]));
		free_array(&arr);
	}
}
