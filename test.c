/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 15:12:51 by ele-cren          #+#    #+#             */
/*   Updated: 2017/02/06 13:46:56 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <mlx.h>
#include <stdlib.h>
#include <math.h>
#include <fdf.h>
#include <libft.h>

#define RGB(r, g, b)(256 * 256 * (int)(r) + 256 * (int)(g) + (int)(b))

int		ft_key(int keycode, void *param)
{
	if (keycode == 53)
		exit (0);
	return (0);
}

int		main(int ac, char **av)
{
	void	*mlx;
	void	*win;
	void	*img;
	int		x1, x2, y1, y2 = 0;
	int		y;
	t_color	color;
	int		i;

	x1 = 50;
	x2 = 100;
	y1 = 50;
	y2 = 200;
	y = 20;
	if ((mlx = mlx_init()) == NULL)
		exit (1);
	win = mlx_new_window(mlx, 200, 200, "Ma fenetre");
	ft_init_colors(&color);
	color.color1hex = "0xFFFFFF";
	color.color2hex = "0x693F26";
	while (y < 150)
	{
		i = 10;
		while (i < 195)
		{
			mlx_pixel_put(mlx, win, i, y, ft_gradient(color, 10, 195, i));
			i++;
		}
		y++;
	}
	/*while (y <= y2)
	{
		mlx_pixel_put(mlx, win, x1 + ((x2 -x1) * (y - y1)) / (y2 - y1), y, 0xFFFFFF);
		y++;
	}*/
	mlx_key_hook(win, ft_key, 0);
	mlx_loop(mlx);
}
