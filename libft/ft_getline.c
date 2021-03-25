/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabdelba <nabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 00:58:45 by nabdelba          #+#    #+#             */
/*   Updated: 2021/03/25 13:18:18 by nabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list		*handle_file(t_list **list, int fd)
{
	t_list			*tmp;

	tmp = *list;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("", fd);
	ft_lstadd(list, tmp);
	return (tmp);
}

static int			read_file(char **tmp, t_list **file, int fd, int *sz)
{
	char			buff[BUFF_SIZE + 1];

	while ((*sz = read(fd, buff, BUFF_SIZE)) && *sz != 0)
	{
		buff[*sz] = '\0';
		*tmp = ft_strdup((char *)(*file)->content);
		free((*file)->content);
		if (!((*file)->content = ft_strjoin(*tmp, buff)))
			return (0);
		free(*tmp);
		if (ft_strchr((char *)(*file)->content, '\n'))
			break ;
	}
	return (1);
}

int					check_line(t_list *node, char **line)
{
	if (!(*line = ft_strdup(node->content)))
		return (0);
	ft_strclr(node->content);
	return (1);
}

int					ft_getline(const int fd, char **line)
{
	static t_list	*file;
	int				sz;
	t_list			*node;
	char			*tmp;

	if ((read(fd, NULL, 0) < 0 || fd < 0 || !line))
		return (-1);
	node = handle_file(&file, fd);
	if (!(read_file(&tmp, &node, fd, &sz)))
		return (-1);
	if (!ft_strlen((char *)node->content) && sz == 0)
		return (0);
	if (!ft_strchr(node->content, '\n') && ft_strlen((char *)node->content))
		return (check_line(node, line));
	tmp = ft_strdup(node->content);
	if (!(*line = ft_strsub(tmp, 0, (ft_strchr(tmp, '\n') - tmp))))
		return (0);
	free(node->content);
	node->content = ft_strdup(ft_strchr(tmp, '\n') + 1);
	free(tmp);
	return (1);
}
