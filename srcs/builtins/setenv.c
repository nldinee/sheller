/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabdelba <nabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:25:53 by nabdelba          #+#    #+#             */
/*   Updated: 2021/03/22 16:26:30 by nabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void		ft_setenv(char **cmdargs, t_env **env)
{
	int		i;
	t_env	*e;

	i = 0;
	while (cmdargs[i])
		i++;
	if (i != 3)
		ft_putendl("Too few, many arguments.");
	else
	{
		e = get_env(env, cmdargs[1]);
		if (e)
		{
			free(e->value);
			e->value = ft_strdup(cmdargs[2]);
		}
		else
			env_append(env, new_env(cmdargs[1], cmdargs[2]));
	}
}
