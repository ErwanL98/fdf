/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 14:39:34 by ele-cren          #+#    #+#             */
/*   Updated: 2017/02/16 14:02:35 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>

t_llist	*ft_change_list(t_llist *list, t_size size)
{
	while (list->next)
	{
		list->xiso = (list->x - list->y) * size.scale;
		list->yiso = (list->x + list->y) * (size.scale / 2);
		list->yiso -= list->z * size.deep;
		list = list->next;
	}
	list->xiso = (list->x - list->y) * size.scale;
	list->yiso = (list->x + list->y) * (size.scale / 2);
	list->yiso -= list->z * size.deep;
	while (list->prev)
		list = list->prev;
	return (list);
}

void	ft_put2(t_llist *list, t_mlx *ml, t_size size)
{
	t_color	color;

	ft_init_colors(&color);
	while (list->prev)
		list = list->prev;
	if (ft_check_color(list) == 1)
		color.check = 1;
	ml->img2 = mlx_new_image(ml->mlx, size.nbcoor, size.nbline);
	ml->data = (int *)mlx_get_data_addr(ml->img2, &ml->bpp, &ml->sizeline, \
	&ml->endian);
	while (list)
	{
		color.color1hex = list->color;
		ml->data[list->x + (list->y * size.nbcoor)] = \
			ft_choose_color_min(size, color, list);
		list = list->next;
	}
}

void	ft_minim(t_param *param, t_event *event)
{
	if (event->m == 1)
	{
		mlx_clear_window(param->mlx.mlx, param->mlx.win);
		mlx_put_image_to_window(param->mlx.mlx, param->mlx.win, \
		param->mlx.img, event->x, event->y);
		event->m = 0;
	}
	else
	{
		mlx_put_image_to_window(param->mlx.mlx, param->mlx.win, \
		param->mlx.img2, 0, 0);
		event->m = 1;
	}
}

void	ft_free_list(t_param *param)
{
	t_llist		*tmp;

	while (param->list->prev)
		param->list = param->list->prev;
	while ((tmp = param->list) != NULL)
	{
		param->list = param->list->next;
		free(tmp->color);
		free(tmp);
	}
}

void	ft_reset(t_param *param, t_event *event)
{
	event->x = 0;
	event->y = 0;
	param->size.scale = param->size.svscale;
	mlx_clear_window(param->mlx.mlx, param->mlx.win);
	mlx_destroy_image(param->mlx.mlx, param->mlx.img);
	param->list = ft_change_list(param->list, param->size);
	ft_check_size(&param->size, param->list);
	param->mlx.img = mlx_new_image(param->mlx.mlx, param->size.width, \
		param->size.height);
	param->mlx.data = (int *)mlx_get_data_addr(param->mlx.img, \
		&param->mlx.bpp, &param->mlx.sizeline, &param->mlx.endian);
	ft_put(param->list, param->size, &param->mlx);
	mlx_put_image_to_window(param->mlx.mlx, param->mlx.win, \
		param->mlx.img, 0, 0);
	if (event->m == 1)
		mlx_put_image_to_window(param->mlx.mlx, param->mlx.win, \
		param->mlx.img2, 0, 0);
}
