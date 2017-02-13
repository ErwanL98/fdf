/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 15:34:14 by ele-cren          #+#    #+#             */
/*   Updated: 2017/02/13 16:17:38 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <math.h>
#include <libft.h>
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

int		ft_color_alt(t_size size, int z)
{
	t_color	color;

	ft_init_colors(&color);
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

int		ft_gradient(t_color color, int min, int max, int current)
{
	int		i;
	t_rgb	r1;
	t_rgb	r2;
	t_rgb	r3;

	i = -1;
	r1 = ft_hex_to_rgb(color.color1hex);
	r2 = ft_hex_to_rgb(color.color2hex);
	r3 = r1;
	while (++i < fabs((double)(current - min)))
	{
		r3.r -= (r1.r - r2.r) / fabs((double)(max - min));
		r3.g -= (r1.g - r2.g) / fabs((double)(max - min));
		r3.b -= (r1.b - r2.b) / fabs((double)(max - min));
	}
	color.color3hex = ft_rgb_to_hex(r3);
	color.color = ft_hex_to_dec(color.color3hex);
	free(color.color3hex);
	return (color.color);
}

int		ft_check_color(t_llist *list)
{
	t_llist	*tmp;
	char	*str;

	str = "0xFFFFFF";
	tmp = list;
	while (list != NULL)
	{
		if (ft_strcmp(list->color, str) != 0)
			return (1);
		if (list->next != NULL)
			list = list->next;
		else
			list = NULL;
	}
	return (0);
}

int		ft_choose_color(t_size size, t_draw draw, t_color color)
{
	if (color.check == 0)
		return (ft_color_alt(size, (draw.a * draw.tmp) + draw.b));
	else
		return (ft_hex_to_dec(color.color1hex));
}
