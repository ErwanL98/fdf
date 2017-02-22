/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 16:54:54 by ele-cren          #+#    #+#             */
/*   Updated: 2017/02/22 11:41:27 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <libft.h>
#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>
#include <unistd.h>

int		ft_key(int keycode, t_param *param)
{
	static t_event	event = {0, 0, 0};

	if (keycode == 53)
	{
		ft_free_list(param);
		mlx_destroy_image(param->mlx.mlx, param->mlx.img);
		mlx_destroy_image(param->mlx.mlx, param->mlx.img2);
		mlx_destroy_window(param->mlx.mlx, param->mlx.win);
		exit(0);
	}
	else if (keycode == 123 || keycode == 124)
		ft_move_lr(param, keycode, &event);
	else if (keycode == 126 || keycode == 125)
		ft_move_tb(param, keycode, &event);
	else if (keycode == 24 || keycode == 27)
		ft_zoom(param, keycode, &event);
	else if (keycode == 15)
		ft_reset(param, &event);
	else if (keycode == 46)
		ft_minim(param, &event);
	return (0);
}

void	ft_zoom(t_param *param, int keycode, t_event *event)
{
	if (keycode == 24)
	{
		param->size.scale += 1;
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
		param->mlx.img, event->x, event->y);
		if (event->m == 1)
			mlx_put_image_to_window(param->mlx.mlx, param->mlx.win, \
				param->mlx.img2, 0, 0);
	}
	else
		ft_unzoom(param, event);
}

void	ft_unzoom(t_param *param, t_event *event)
{
	param->size.scale -= 1;
	if (param->size.scale == 0)
		param->size.scale = 1;
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
	param->mlx.img, event->x, event->y);
	if (event->m == 1)
		mlx_put_image_to_window(param->mlx.mlx, param->mlx.win, \
			param->mlx.img2, 0, 0);
}

void	ft_move_lr(t_param *param, int keycode, t_event *event)
{
	if (keycode == 123)
	{
		mlx_clear_window(param->mlx.mlx, param->mlx.win);
		event->x += 50;
		mlx_put_image_to_window(param->mlx.mlx, param->mlx.win, \
		param->mlx.img, event->x, event->y);
	}
	else
	{
		mlx_clear_window(param->mlx.mlx, param->mlx.win);
		event->x -= 50;
		mlx_put_image_to_window(param->mlx.mlx, param->mlx.win, \
		param->mlx.img, event->x, event->y);
	}
	if (event->m == 1)
		mlx_put_image_to_window(param->mlx.mlx, param->mlx.win, \
			param->mlx.img2, 0, 0);
}

void	ft_move_tb(t_param *param, int keycode, t_event *event)
{
	if (keycode == 126)
	{
		mlx_clear_window(param->mlx.mlx, param->mlx.win);
		event->y += 50;
		mlx_put_image_to_window(param->mlx.mlx, param->mlx.win, \
		param->mlx.img, event->x, event->y);
	}
	else
	{
		mlx_clear_window(param->mlx.mlx, param->mlx.win);
		event->y -= 50;
		mlx_put_image_to_window(param->mlx.mlx, param->mlx.win, \
		param->mlx.img, event->x, event->y);
	}
	if (event->m == 1)
		mlx_put_image_to_window(param->mlx.mlx, param->mlx.win, \
			param->mlx.img2, 0, 0);
}
