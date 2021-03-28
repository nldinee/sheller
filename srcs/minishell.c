/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabdelba <nabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:50:15 by nabdelba          #+#    #+#             */
/*   Updated: 2021/03/28 17:36:00 by nabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		init_shell(t_env **env)
{
	char	*cmd;
	char	*path;
	char	buff[1024];

	cmd = NULL;
	path = NULL;
	while (1)
	{
		getcwd(buff, 1024);
		ft_putstr(buff);
		ft_putstr(" -> ");
		ft_getline(0, &cmd);
		if (!cmd)
			break ;
		handle_cmd(&cmd, env);
		ft_strdel(&cmd);
	}
}

int			main(int ac, char **av, char **environ)
{
	t_env	*env;
	t_env	*tmp;

	(void)av;
	(void)ac;
	env = NULL;
	tmp = NULL;
	copy_env(&env, environ);
	init_shell(&env);
	free_env(&env);
	return (0);
}
