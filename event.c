/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 16:54:54 by ele-cren          #+#    #+#             */
/*   Updated: 2017/02/10 16:35:23 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <libft.h>
#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>

int		ft_key(int keycode, void *param)
{
	static int	x = 0;
	static int	y = 0;

	(void)*param;
	if (keycode == 53)
		exit(0);
	if (keycode == 123 || keycode == 124)
		ft_move_lr(param, keycode, &x, &y);
	else if (keycode == 126 || keycode == 125)
		ft_move_tb(param, keycode, &x, &y);
//	else if (keycode == 24 || keycode == 27)
//		ft_zoom(param, keycode, &x, &y);
	return (0);
}

/*void	ft_zoom(t_param *param, int keycode, int *x, int *y)
{
	t_llist	*tmp;

	if (keycode == 24)
	{
		param->size.scale += 5;
		mlx_clear_window(param->mlx.mlx, param->mlx.win);
		while (param->list->next != NULL)
		{
			param->list->xiso = (param->list->x - param->list->y) * param->size\
			.scale;
			param->list->yiso = (param->list->x + param->list->y) * (param->size\
			.scale / 2);
			param->list = param->list->next;
		}
		param->list->xiso = (param->list->x - param->list->y) * param->size\
		.scale;
		param->list->yiso = (param->list->x + param->list->y) * (param->size\
		.scale / 2);
		while (param->list->prev != NULL)
			param->list = param->list->prev;
		mlx_destroy_image(param->mlx.mlx, param->mlx.img);
		ft_check_size(&param->size, param->list);
		param->mlx.img = mlx_new_image(param->mlx.mlx, param->size.width, \
		param->size.height);
		param->mlx.data = (int *)mlx_get_data_addr(param->mlx.mlx, &param->mlx.\
		bpp, &param->mlx.sizeline, &param->mlx.endian);
		ft_put(tmp, param->size, &param->mlx);
		mlx_put_image_to_window(param->mlx.mlx, param->mlx.win, \
		param->mlx.img, *x, *y);
	}
}*/

void	ft_move_lr(t_param *param, int keycode, int *x, int *y)
{
	if (keycode == 123)
	{
		mlx_clear_window(param->mlx.mlx, param->mlx.win);
		*x += 50;
		mlx_put_image_to_window(param->mlx.mlx, param->mlx.win, \
		param->mlx.img, *x, *y);
	}
	else
	{
		mlx_clear_window(param->mlx.mlx, param->mlx.win);
		*x -= 50;
		mlx_put_image_to_window(param->mlx.mlx, param->mlx.win, \
		param->mlx.img, *x, *y);
	}
}

void	ft_move_tb(t_param *param, int keycode, int *x, int *y)
{
	if (keycode == 126)
	{
		mlx_clear_window(param->mlx.mlx, param->mlx.win);
		*y += 50;
		mlx_put_image_to_window(param->mlx.mlx, param->mlx.win, \
		param->mlx.img, *x, *y);
	}
	else
	{
		mlx_clear_window(param->mlx.mlx, param->mlx.win);
		*y -= 50;
		mlx_put_image_to_window(param->mlx.mlx, param->mlx.win, \
		param->mlx.img, *x, *y);
	}
}
