/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 14:54:08 by ele-cren          #+#    #+#             */
/*   Updated: 2017/02/10 15:38:55 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <fdf.h>
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_check_size(t_size *size, t_llist *list)
{
	while (list != NULL)
	{
		if (list->xiso > size->xmax)
			size->xmax = list->xiso;
		if (list->xiso < size->xmin)
			size->xmin = list->xiso;
		if (list->yiso > size->ymax)
			size->ymax = list->yiso;
		if (list->yiso < size->ymin)
			size->ymin = list->yiso;
		if (list->z > size->zmax)
			size->zmax = list->z;
		if (list->z < size->zmin)
			size->zmin = list->z;
		if (list->next != NULL)
			list = list->next;
		else
			list = NULL;
	}
	size->width = (size->xmax - size->xmin) + 50;
	size->height = (size->ymax - size->ymin) + 50;
}

void	ft_mlx(t_llist *list, t_size size)
{
	t_mlx	ml;
	t_param	param;

	ft_init_mlx(&ml);
	ft_check_size(&size, list);
	ml.mlx = mlx_init();
	ml.win = mlx_new_window(ml.mlx, size.width, size.height, "FDF");
	ml.img = mlx_new_image(ml.mlx, size.width, size.height);
	ml.data = (int *)mlx_get_data_addr(ml.img, &ml.bpp, &ml.sizeline, \
		&ml.endian);
	ft_getz(list, &size);
	ft_put(list, size, &ml);
	param.size = size;
	param.mlx = ml;
	param.list = list;
	mlx_put_image_to_window(ml.mlx, ml.win, ml.img, 0, 0);
	mlx_key_hook(ml.win, ft_key, &param);
	mlx_loop(ml.mlx);
}

void	ft_put(t_llist *list, t_size size, t_mlx *ml)
{
	t_llist	*tmp;
	int		i;
	t_color	col;

	ft_init_colors(&col);
	i = -1;
	tmp = list;
	if (ft_check_color(list) == 1)
		col.check = 1;
	while (tmp->next != NULL)
	{
		if (tmp->y == tmp->next->y)
			ft_drawx(ml, tmp, size, col);
		tmp = tmp->next;
	}
	while (++i < size.nbcoor * (size.nbline - 1))
	{
		ft_drawy(ml, list, size, col);
		list = list->next;
	}
}

void	ft_drawy(t_mlx *ml, t_llist *list, t_size size, t_color col)
{
	t_draw	draw;
	int		i;

	i = -1;
	draw.x1 = list->xiso;
	draw.y1 = list->yiso;
	draw.z1 = list->z;
	col.color1hex = list->color;
	while (++i < size.nbcoor)
		list = list->next;
	draw.x2 = list->xiso;
	draw.y2 = list->yiso;
	draw.z2 = list->z;
	draw.a = (draw.y2 == draw.y1) ? ((draw.z2 - draw.z1) / (draw.x2 - draw.x1))\
	: ((draw.z2 - draw.z1) / (draw.y2 - draw.y1));
	draw.b = (draw.y1 == draw.y2) ? draw.z1 - (draw.a * draw.x1) : \
		draw.z1 - (draw.a * draw.y1);
	draw.x = draw.x1;
	draw.y = draw.y1;
	ft_drawseg(draw, ml, size, col);
}

void	ft_drawx(t_mlx *ml, t_llist *list, t_size size, t_color col)
{
	t_draw	draw;

	draw.x1 = list->xiso;
	draw.y1 = list->yiso;
	draw.z1 = list->z;
	col.color1hex = list->color;
	list = list->next;
	draw.x2 = list->xiso;
	draw.y2 = list->yiso;
	draw.z2 = list->z;
	draw.a = (draw.y2 == draw.y1) ? ((draw.z2 - draw.z1) / (draw.x2 - draw.x1))\
	: ((draw.z2 - draw.z1) / (draw.y2 - draw.y1));
	draw.b = (draw.y1 == draw.y2) ? draw.z1 - (draw.a * draw.x1) : \
		draw.z1 - (draw.a * draw.y1);
	draw.x = draw.x1;
	draw.y = draw.y1;
	ft_drawseg(draw, ml, size, col);
}
