/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabdelba <nabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:27:49 by nabdelba          #+#    #+#             */
/*   Updated: 2021/03/22 16:37:20 by nabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int				check_errs(char *str)
{
	DIR			*dir;

	dir = opendir(str);
	if (dir)
	{
		closedir(dir);
		return (1);
	}
	else
	{
		if (access(str, F_OK) == -1)
		{
			ft_putstr("cd: ");
			ft_putstr(str);
			ft_putendl(" No such file or directory");
		}
		else if (access(str, R_OK | W_OK | X_OK) == -1)
		{
			ft_putstr("cd: ");
			ft_putstr(str);
			ft_putendl(" Permission denied");
		}
		return (0);
	}
}

static void		swap_env(t_env **env, char *key, char *value)
{
	env_delete(env, key);
	env_append(env, new_env(key, value));
}

static void		check_oldpwd(t_env **env, char *buff)
{
	t_env		*oldpwd;

	if (!(oldpwd = get_env(env, "OLDPWD")))
		ft_putendl("OLDPWD not set");
	else
	{
		chdir(oldpwd->value);
		swap_env(env, "OLDPWD", buff);
	}
}

void			ft_cd(char **cmdargs, t_env **env)
{
	char		buff[4096];
	t_env		*e;
	t_env		*pwd;

	getcwd(buff, 4096);
	if (!cmdargs[1])
	{
		if (!(e = get_env(env, "HOME")))
			ft_putendl("HOME not set.");
		else
		{
			chdir(e->value);
			swap_env(env, "PWD", e->value);
		}
	}
	else if (cmdargs[1][0] == '-')
		check_oldpwd(env, buff);
	else if (check_errs(cmdargs[1]))
	{
		if (!(pwd = get_env(env, "PWD")))
			env_append(env, new_env("PWD", cmdargs[1]));
		chdir(cmdargs[1]);
		swap_env(env, "OLDPWD", buff);
	}
}
