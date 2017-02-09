/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 13:36:36 by ele-cren          #+#    #+#             */
/*   Updated: 2017/02/09 11:54:37 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <libft.h>
#include <fdf.h>
#include <get_next_line.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

t_llist	*ft_callread(char *av, t_size size)
{
	t_read	read;

	read.begin = NULL;
	read.tmp = NULL;
	read.line = NULL;
	read.tab = NULL;
	if ((read.fd = open(av, O_RDONLY)) == -1)
		ft_error_file();
	ft_read(&read, size);
	if ((close(read.fd)) == -1)
		ft_error_file();
	return (read.begin);
}

void	ft_read(t_read *re, t_size size)
{
	t_coor	coor;

	coor.y = 0;
	while (get_next_line(re->fd, &re->line))
	{
		coor.x = 0;
		re->tab = ft_strsplit(re->line, ' ');
		ft_assign(re, size, &coor);
		coor.y++;
		free(re->line);
	}
	free(re->tab);
}

void	ft_assign(t_read *re, t_size size, t_coor *coor)
{
	while (re->tab[coor->x])
	{
		if (re->begin == NULL)
		{
			re->begin = ft_create(*coor, re->tab[coor->x], NULL, size);
			re->tmp = re->begin;
		}
		else
		{
			re->tmp->next = ft_create(*coor, re->tab[coor->x], re->tmp, size);
			re->tmp = re->tmp->next;
		}
		free(re->tab[coor->x]);
		coor->x++;
	}
}

t_llist	*ft_create(t_coor coor, char *tab, t_llist *tmp, t_size size)
{
	t_llist	*list;
	char	*tp;

	tp = NULL;
	list = NULL;
	if ((list = (t_llist *)malloc(sizeof(t_llist))) == NULL)
		exit(1);
	list->x = coor.x;
	list->y = coor.y;
	list->color = ((tp = ft_strchr(tab, ','))) ? ft_strdup(tp + 1) : "0xFFFFFF";
	list->z = ft_atoi(tab);
	list->xiso = (coor.x - coor.y) * size.scale;
	list->yiso = (coor.x + coor.y) * (size.scale / 2);
	list->yiso -= list->z * size.deep;
	list->next = NULL;
	list->prev = tmp;
	return (list);
}

void	ft_getz(t_llist *list, t_size *size)
{
	while (list != NULL)
	{
		if (list->z > size->zmax)
			size->zmax = list->z;
		if (list->z < size->zmin)
			size->zmin = list->z;
		if (list->next != NULL)
			list = list->next;
		else
			list = NULL;
	}
}
