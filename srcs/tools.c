/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabdelba <nabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 15:13:05 by nabdelba          #+#    #+#             */
/*   Updated: 2021/03/22 15:14:24 by nabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		check_file_perm(char *path)
{
	if ((access(path, F_OK) != -1))
	{
		if (access(path, X_OK))
		{
			ft_putstr(path);
			ft_putendl(": Permission Denied.");
		}
	}
	else
	{
		ft_putstr(path);
		ft_putendl(" : Command not found.");
	}
}

char		**env_to_array(t_env *env)
{
	char	**array;
	char	*envi;
	int		i;

	i = 0;
	array = (char **)ft_memalloc(sizeof(char *) * list_len(env) + 1);
	while (env)
	{
		envi = ft_strnew((int)ft_strlen(env->key) + 1 +
		(int)ft_strlen(env->value));
		ft_strcpy(envi, env->key);
		ft_strcat(envi, "=");
		ft_strcat(envi, env->value);
		array[i++] = ft_strdup(envi);
		env = env->next;
		free(envi);
	}
	array[i] = NULL;
	return (array);
}

int			list_len(t_env *env)
{
	int		i;

	i = 0;
	while (env)
	{
		i++;
		env = env->next;
	}
	return (i);
}

void		free_array(char ***arr)
{
	int		i;

	i = 0;
	while ((*arr)[i])
		free((*arr)[i++]);
	free((*arr));
	(*arr) = NULL;
}

void		free_env(t_env **env)
{
	t_env	*hlp;

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
