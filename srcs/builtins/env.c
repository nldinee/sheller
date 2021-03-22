/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabdelba <nabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:24:48 by nabdelba          #+#    #+#             */
/*   Updated: 2021/03/22 16:24:56 by nabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void		ft_env(t_env *env)
{
	while (env)
	{
		ft_putstr(env->key);
		ft_putchar('=');
		ft_putstr(env->value);
		ft_putchar('\n');
		env = env->next;
	}
}
