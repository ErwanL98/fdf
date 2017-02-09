/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 15:12:51 by ele-cren          #+#    #+#             */
/*   Updated: 2017/02/09 13:31:15 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <mlx.h>
#include <stdlib.h>
#include <math.h>
#include <fdf.h>
#include <libft.h>
#include <math.h>

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
	int		bpp;
	int		sizeline;
	int		endian;
	int		*data;
	int		x1, x2, y1, y2 = 0;
	int		x;
	t_color	color;
	int		i;
	int		y;

	if ((mlx = mlx_init()) == NULL)
		exit (1);
	win = mlx_new_window(mlx, 200, 200, "Ma fenetre");
	img = mlx_new_image(mlx, 100, 100);
	data = (int *)mlx_get_data_addr(img, &bpp, &sizeline, &endian);
	y = 0;
	while (y < 50)
	{
		x = 0;
		while (x < 90)
		{
			data[x + (y * 100)] = 0x00FF00;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx, win, img, -50, 0);
/*	ft_init_colors(&color);
	color.color1hex = "0xFFFFFF";
	color.color2hex = "0x693F26";
	while (x < 150 )
	{
		i = 195;
		while (i > 10)
		{
			mlx_pixel_put(mlx, win, x, i, ft_gradient(color, 195, 10, i));
			i--;
		}
		x++;
	}*/
	/*while (y <= y2)
	{
		mlx_pixel_put(mlx, win, x1 + ((x2 -x1) * (y - y1)) / (y2 - y1), y, 0xFFFFFF);
		y++;
	}*/
	mlx_key_hook(win, ft_key, 0);
	mlx_loop(mlx);
}
