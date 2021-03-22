/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabdelba <nabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:20:04 by nabdelba          #+#    #+#             */
/*   Updated: 2021/03/22 16:20:17 by nabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void		ft_echo(char **cmdargs)
{
	int		i;

	i = 1;
	while (cmdargs[i])
	{
		ft_putstr(cmdargs[i]);
		if (cmdargs[i + 1])
			ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
}
