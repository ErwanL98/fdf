/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 15:30:18 by ele-cren          #+#    #+#             */
/*   Updated: 2017/02/14 15:58:35 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <math.h>
#include <mlx.h>
#include <libft.h>
#include <stdio.h>

void	ft_drawseg(t_draw draw, t_mlx *ml, t_size size, t_color col)
{
	if (fabs((double)draw.x2 - draw.x1) >= fabs((double)draw.y2 - draw.y1))
		ft_low(draw, ml, size, col);
	else
		ft_high(draw, ml, size, col);
}

void	ft_high(t_draw draw, t_mlx *ml, t_size size, t_color col)
{
	if (draw.y2 > draw.y1)
	{
		while (draw.y <= draw.y2)
		{
			draw.tmp = (draw.y1 == draw.y2) ? draw.x : draw.y;
			ml->data[25 - size.xmin + (int)draw.x1 + (((int)draw.x2 - \
			(int)draw.x1) * ((int)draw.y - (int)draw.y1)) / ((int)draw.y2 - \
			(int)draw.y1) + ((25 * size.width) - (size.ymin * size.width)\
			+ ((int)draw.y * size.width))] = ft_choose_color(size, draw, col);
			draw.y++;
		}
	}
	else
	{
		while (draw.y >= draw.y2)
		{
			draw.tmp = (draw.y1 == draw.y2) ? draw.x : draw.y;
			ml->data[25 - size.xmin + (int)draw.x1 + (((int)draw.x2 - \
			(int)draw.x1) * ((int)draw.y - (int)draw.y1)) / ((int)draw.y2 - \
			(int)draw.y1) + ((25 * size.width) - (size.ymin * size.width)\
			+ ((int)draw.y * size.width))] = ft_choose_color(size, draw, col);
			draw.y--;
		}
	}
}

void	ft_low(t_draw draw, t_mlx *ml, t_size size, t_color col)
{
	if (draw.x2 > draw.x1)
	{
		while (draw.x++ <= draw.x2)
		{
			draw.tmp = (draw.y1 == draw.y2) ? draw.x : draw.y;
			draw.y = (int)draw.y1 + (((int)draw.y2 - (int)draw.y1) * ((int)\
			draw.x - (int)draw.x1)) / ((int)draw.x2 - (int)draw.x1);
			ml->data[25 - size.xmin + (int)draw.x + ((25 * size.\
			width) - (size.ymin * size.width) + ((int)draw.y * size.width))] = \
			ft_choose_color(size, draw, col);
		}
	}
	else
	{
		while (draw.x-- >= draw.x2)
		{
			draw.tmp = (draw.y1 == draw.y2) ? draw.x : draw.y;
			draw.y = (int)draw.y1 + (((int)draw.y2 - (int)draw.y1) * ((int)\
			draw.x - (int)draw.x1)) / ((int)draw.x2 - (int)draw.x1);
			ml->data[25 - size.xmin + (int)draw.x + ((25 * size.\
			width) - (size.ymin * size.width) + ((int)draw.y * size.width))] = \
			ft_choose_color(size, draw, col);
		}
	}
}
