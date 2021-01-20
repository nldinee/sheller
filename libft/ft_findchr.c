/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabdelba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 03:39:56 by nabdelba          #+#    #+#             */
/*   Updated: 2019/04/30 03:55:33 by nabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_findchr(const char *s, char c)
{
	int		count_char;

	count_char = 0;
	while (s[count_char] != c && s[count_char])
	{
		count_char++;
	}
	return (count_char);
}
