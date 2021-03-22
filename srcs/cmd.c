/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabdelba <nabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 15:08:05 by nabdelba          #+#    #+#             */
/*   Updated: 2021/03/22 16:41:40 by nabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*make_path(char *executable, char *path)
{
	char	*tmp;

	tmp = ft_strnew((int)ft_strlen(path) + 1 +
	(int)ft_strlen(executable));
	ft_strcpy(tmp, path);
	ft_strcat(tmp, "/");
	ft_strcat(tmp, executable);
	return (tmp);
}

static char	*check_cmd(t_env *env, char *executable)
{
	char	*path;
	char	**paths;
	char	*tmp;
	int		i;

	if (executable[0] != '.')
	{
		path = get_env(&env, "PATH")->value;
		paths = ft_strsplit(path, ':');
		i = 0;
		while (paths[i])
		{
			tmp = make_path(executable, paths[i++]);
			if (access(tmp, F_OK) != -1)
			{
				if (paths)
					free_array(&paths);
				return (tmp);
			}
			else
				free(tmp);
		}
		free_array(&paths);
	}
	return (ft_strdup(executable));
}

static void	exec_cmd(char *cmd, char **cmdargs, t_env **env)
{
	char	**env_arr;
	int		pid;

	env_arr = NULL;
	env_arr = env_to_array((*env));
	if ((pid = fork()))
		wait(0);
	else
	{
		if (execve(cmd, cmdargs, env_arr) == -1)
		{
			check_file_perm(cmdargs[0]);
			exit(0);
		}
	}
	free_array(&env_arr);
}

void		handle_cmd(char **cmd, t_env **env)
{
	char	**cmdargs;
	char	*fullpath;
	int		i;

	cmdargs = NULL;
	fullpath = NULL;
	i = 0;
	cmdargs = ft_strsplitstr(*cmd, "\r\t \"");
	if (!cmdargs)
		return ;
	handle_exp(cmdargs, env);
	if (check_builtins(cmdargs[0]))
		exec_builtins(cmd, cmdargs[0], &cmdargs, env);
	else
	{
		if (get_env(env, "PATH"))
			fullpath = check_cmd(*env, cmdargs[0]);
		else
			fullpath = ft_strdup(cmdargs[0]);
		exec_cmd(fullpath, cmdargs, env);
		ft_strdel(&fullpath);
	}
	free_array(&cmdargs);
}
