/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 10:49:11 by ele-cren          #+#    #+#             */
/*   Updated: 2017/02/09 12:35:51 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <fdf.h>

void	ft_init_size(t_size *size)
{
	size->height = 0;
	size->width = 0;
	size->scale = 20;
	size->scale2 = 5;
	size->xmin = 0;
	size->xmax = 0;
	size->ymin = 0;
	size->ymax = 0;
	size->nbline = 0;
	size->nbcoor = 0;
	size->zmax = 0;
	size->deep = 1;
	size->zmin = 0;
	size->mvx = 25;
	size->mvy = 25;
	size->x = 0;
}

void	ft_init_args(t_args *ag)
{
	ag->arg1 = "-d";
	ag->arg2 = "-s";
	ag->arg3 = "-b";
}

void	ft_init_mlx(t_mlx *mlx)
{
	mlx->mlx = NULL;
	mlx->win = NULL;
	mlx->img1 = NULL;
	mlx->img2 = NULL;
	mlx->img3 = NULL;
	mlx->img4 = NULL;
	mlx->bpp1 = 0;
	mlx->sizeline1 = 0;
	mlx->endian1 = 0;
	mlx->bpp2 = 0;
	mlx->sizeline2 = 0;
	mlx->endian2 = 0;
	mlx->bpp3 = 0;
	mlx->sizeline3 = 0;
	mlx->endian3 = 0;
	mlx->bpp4 = 0;
	mlx->sizeline4 = 0;
	mlx->endian4 = 0;
}

void	ft_init_colors(t_color *color)
{
	color->colorprev = "0xFFFFFF";
	color->colornext = "0xFFFFFF";
	color->color1hex = "0xFFFFFF";
	color->color2hex = "0xFFFFFF";
	color->color3hex = "0xFFFFFF";
	color->color = 0;
	color->check = 0;
}

void	ft_init_pos(t_imgpos *imgpos)
{
	imgpos->x = 0;
	imgpos->x1 = 0;
	imgpos->x2 = 0;
	imgpos->y = 0;
	imgpos->y1 = 0;
	imgpos->y2 = 0;
}
