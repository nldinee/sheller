/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabdelba <nabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:20:36 by nabdelba          #+#    #+#             */
/*   Updated: 2021/03/22 16:23:47 by nabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int			check_builtins(char *cmd)
{
	if (!ft_strcmp(cmd, "cd"))
		return (1);
	else if (!ft_strcmp(cmd, "setenv"))
		return (1);
	else if (!ft_strcmp(cmd, "unsetenv"))
		return (1);
	else if (!ft_strcmp(cmd, "env"))
		return (1);
	else if (!ft_strcmp(cmd, "echo"))
		return (1);
	else if (!ft_strcmp(cmd, "exit"))
		return (1);
	return (0);
}

void		exec_builtins(char **input, char *cmd, char ***cmdargs, t_env **env)
{
	if (ft_strcmp("setenv", cmd) == 0)
		ft_setenv(*cmdargs, env);
	if (ft_strcmp("exit", cmd) == 0)
		ft_exit(cmdargs, env, input);
	if (ft_strcmp("cd", cmd) == 0)
		ft_cd(*cmdargs, env);
	if (ft_strcmp("unsetenv", cmd) == 0)
		ft_unsetenv(*cmdargs, env);
	if (ft_strcmp("echo", cmd) == 0)
		ft_echo(*cmdargs);
	if (ft_strcmp("env", cmd) == 0)
		ft_env(*env);
}
