/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 15:30:18 by ele-cren          #+#    #+#             */
/*   Updated: 2017/02/06 16:15:53 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <math.h>
#include <libft.h>
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

/*void	ft_drawseg(t_draw draw, t_mlx ml, t_size size, int color)
{
	int		color2;

	color2 = (color == 0) ? 0xFFFFFF : color;
	if (fabs((double)draw.x2 - draw.x1) >= fabs((double)draw.y2 - draw.y1))
		ft_case1(draw, ml, size, color2);
	else
		ft_case2(draw, ml, size, color2);
}

void	ft_case2(t_draw draw, t_mlx ml, t_size size, int color)
{
	if (draw.y2 > draw.y1)
	{
		while (draw.y <= draw.y2)
		{
			mlx_pixel_put(ml.mlx, ml.win, 25 - size.xmin + draw.x1 +\
				((draw.x2 - draw.x1) * (draw.y - draw.y1)) / \
					(draw.y2 - draw.y1), 25 - size.ymin + draw.y, color);
			draw.y++;
		}
	}
	else
	{
		while (draw.y >= draw.y2)
		{
			mlx_pixel_put(ml.mlx, ml.win, 25 - size.xmin + draw.x1 +\
				((draw.x2 - draw.x1) * (draw.y - draw.y1)) / \
					(draw.y2 - draw.y1), 25 - size.ymin + draw.y, color);
			draw.y--;
		}
	}
}

void	ft_case1(t_draw draw, t_mlx ml, t_size size, int color)
{
	if (draw.x2 > draw.x1)
	{
		while (draw.x <= draw.x2)
		{
			mlx_pixel_put(ml.mlx, ml.win, 25 - size.xmin + draw.x, \
					25 - size.ymin + draw.y1 + ((draw.y2 - draw.y1) * \
						(draw.x - draw.x1)) / (draw.x2 - draw.x1), color);
			draw.x++;
		}
	}
	else
	{
		while (draw.x >= draw.x2)
		{
			mlx_pixel_put(ml.mlx, ml.win, 25 - size.xmin + draw.x, \
					25 - size.ymin + draw.y1 + ((draw.y2 - draw.y1) * \
						(draw.x - draw.x1)) / (draw.x2 - draw.x1), color);
			draw.x--;
		}
	}
}*/

int		ft_gradient(t_color color, int min, int max, int current)
{
	int		i;
	int		res;
	t_rgb	r1;
	t_rgb	r2;
	t_rgb	r3;

	i = -1;
	r1 = ft_hex_to_rgb(color.color1hex);
	r2 = ft_hex_to_rgb(color.color2hex);
	r3= r1;
	while (++i < fabs((double)(current - min)))
	{
		r3.r -= (r1.r - r2.r) / (max - min);
		r3.g -= (r1.g - r2.g) / (max - min);
		r3.b -= (r1.b - r2.b) / (max - min);
	}
	color.color3hex = ft_rgb_to_hex(r3);
	color.color = ft_hex_to_dec(color.color3hex);
	return (color.color);
}
