/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 15:30:18 by ele-cren          #+#    #+#             */
/*   Updated: 2017/02/06 16:58:35 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <math.h>
#include <mlx.h>
#include <libft.h>
#include <stdio.h>

void	ft_drawseg(t_draw draw, t_mlx ml, t_size size)
{
	if (fabs((double)draw.x2 - draw.x1) >= fabs((double)draw.y2 - draw.y1))
		ft_low(draw, ml, size);
	else
		ft_high(draw, ml, size);
}

void	ft_high(t_draw draw, t_mlx ml, t_size size)
{
	if (draw.y2 > draw.y1)
	{
		while (draw.y <= draw.y2)
		{
			draw.tmp = (draw.y1 == draw.y2) ? draw.x : draw.y;
			mlx_pixel_put(ml.mlx, ml.win, 25 - size.xmin + draw.x1 + ((draw.x2 \
			- draw.x1) * (draw.y - draw.y1)) / (draw.y2 - draw.y1), 25 - size.\
			ymin + draw.y, ft_color_alt(size, (draw.a * draw.tmp) + draw.b, draw));
			draw.y++;
		}
	}
	else
	{
		while (draw.y >= draw.y2)
		{
			draw.tmp = (draw.y1 == draw.y2) ? draw.x : draw.y;
			mlx_pixel_put(ml.mlx, ml.win, 25 - size.xmin + draw.x1 + ((draw.x2 \
			- draw.x1) * (draw.y - draw.y1)) / (draw.y2 - draw.y1), 25 - size.\
			ymin + draw.y, ft_color_alt(size, (draw.a * draw.tmp) + draw.b, draw));
			draw.y--;
		}
	}
}

void	ft_low(t_draw draw, t_mlx ml, t_size size)
{
	if (draw.x2 > draw.x1)
	{
		while (draw.x <= draw.x2)
		{
			draw.tmp = (draw.y1 == draw.y2) ? draw.x : draw.y;
			draw.y = draw.y1 + ((draw.y2 - draw.y1) * (draw.x - draw.x1))\
			 / (draw.x2 - draw.x1);
			mlx_pixel_put(ml.mlx, ml.win, 25 - size.xmin + draw.x, 25 - size.\
			ymin + draw.y, ft_color_alt(size, (draw.a * draw.tmp) + draw.b, draw));
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
			mlx_pixel_put(ml.mlx, ml.win, 25 - size.xmin + draw.x, 25 - size.\
			ymin + draw.y, ft_color_alt(size, (draw.a * draw.tmp) + draw.b, draw));
			draw.x--;
		}
	}
}

int		ft_color_alt(t_size size, int z, t_draw draw)
{
	t_color	color;

	ft_init_colors(&color);
	z = (draw.z1 == draw.z2) ? draw.z1 : z;
	if (z < 0)
		color.color = 0x162346;
	else if (z == size.zmax)
		color.color = 0xFFFFFF;
	else if (z >= 0 && z <= size.zmax / 3.5)
	{
		color.color1hex = "0x7FDD4C";
		color.color2hex = "0x492D1D";
		color.color = ft_gradient(color, size.zmin, size.zmax / 3.5, z);
	}
	else if (z >= size.zmax / 3.5 && z <= size.zmax)
	{
		color.color1hex = "0x492D1D";
		color.color2hex = "0xFFFFFF";
		color.color = ft_gradient(color, size.zmax / 3.5, size.zmax, z);
	}
	return (color.color);
}
