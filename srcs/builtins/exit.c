/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabdelba <nabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:25:12 by nabdelba          #+#    #+#             */
/*   Updated: 2021/03/22 16:25:39 by nabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void		ft_exit(char ***final, t_env **env, char **input)
{
	if (final)
		free_array(final);
	ft_strdel(input);
	free_env(env);
	exit(0);
}
