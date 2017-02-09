/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 15:30:18 by ele-cren          #+#    #+#             */
/*   Updated: 2017/02/09 13:12:43 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <math.h>
#include <mlx.h>
#include <libft.h>
#include <stdio.h>

void	ft_drawseg(t_draw draw, t_mlx ml, t_size size, t_color col)
{
	if (fabs((double)draw.x2 - draw.x1) >= fabs((double)draw.y2 - draw.y1))
		ft_low(draw, ml, size, col);
	else
		ft_high(draw, ml, size, col);
}

void	ft_high(t_draw draw, t_mlx ml, t_size size, t_color col)
{
	if (draw.y2 > draw.y1)
	{
		while (draw.y <= draw.y2)
		{
			draw.tmp = (draw.y1 == draw.y2) ? draw.x : draw.y;
			mlx_pixel_put(ml.mlx, ml.win, size.mvx - size.xmin + draw.x1 + ((\
			draw.x2 - draw.x1) * (draw.y - draw.y1)) / (draw.y2 - draw.y1), \
			size.mvy - size.ymin + draw.y, ft_choose_color(size, draw, col));
			draw.y++;
		}
	}
	else
	{
		while (draw.y >= draw.y2)
		{
			draw.tmp = (draw.y1 == draw.y2) ? draw.x : draw.y;
			mlx_pixel_put(ml.mlx, ml.win, size.mvx - size.xmin + draw.x1 + ((\
			draw.x2 - draw.x1) * (draw.y - draw.y1)) / (draw.y2 - draw.y1), \
			size.mvy - size.ymin + draw.y, ft_choose_color(size, draw, col));
			draw.y--;
		}
	}
}

void	ft_low(t_draw draw, t_mlx ml, t_size size, t_color col)
{
	if (draw.x2 > draw.x1)
	{
		while (draw.x <= draw.x2)
		{
			draw.tmp = (draw.y1 == draw.y2) ? draw.x : draw.y;
			draw.y = draw.y1 + ((draw.y2 - draw.y1) * (draw.x - draw.x1))\
			/ (draw.x2 - draw.x1);
			mlx_pixel_put(ml.mlx, ml.win, size.mvx - size.xmin + draw.x, \
			size.mvy - size.ymin + draw.y, ft_choose_color(size, draw, col));
			draw.x++;
		}
	}
	else
	{
		while (draw.x >= draw.x2)
		{
			draw.tmp = (draw.y1 == draw.y2) ? draw.x : draw.y;
			draw.y = draw.y1 + ((draw.y2 - draw.y1) * (draw.x - draw.x1))\
			/ (draw.x2 - draw.x1);
			mlx_pixel_put(ml.mlx, ml.win, size.mvx - size.xmin + draw.x, \
			size.mvy - size.ymin + draw.y, ft_choose_color(size, draw, col));
			draw.x--;
		}
	}
}
