/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 14:39:34 by ele-cren          #+#    #+#             */
/*   Updated: 2017/02/13 17:27:29 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <mlx.h>
#include <stdlib.h>

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

void	ft_reset(t_param *param, int *x, int *y)
{
	*x = 0;
	*y = 0;
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
		param->mlx.img, *x, *y);
}
