/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 16:28:12 by ele-cren          #+#    #+#             */
/*   Updated: 2017/02/09 13:12:51 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <fdf.h>
#include <stdio.h>
#include <math.h>

void	ft_create_imgs(t_mlx *ml, t_size size)
{
	ml->img1 = mlx_new_image(ml->mlx, size.scale, size.scale);
	ml->img2 = mlx_new_image(ml->mlx, size.scale, size.scale);
	ml->img3 = mlx_new_image(ml->mlx, size.scale, size.scale);
	ml->img4 = mlx_new_image(ml->mlx, size.scale, size.scale);
	ml->data1 = (int *)mlx_get_data_addr(ml->img1, &ml->bpp1, &ml->sizeline1, \
		&ml->endian1);
	ml->data2 = (int *)mlx_get_data_addr(ml->img2, &ml->bpp2, &ml->sizeline2, \
		&ml->endian2);
	ml->data3 = (int *)mlx_get_data_addr(ml->img3, &ml->bpp3, &ml->sizeline3, \
		&ml->endian3);
	ml->data4 = (int *)mlx_get_data_addr(ml->img4, &ml->bpp4, &ml->sizeline4, \
		&ml->endian4);
	ft_fill_img1(ml, size);
}

void	ft_fill_img1(t_mlx *ml, t_size size)
{
	t_imgpos	img;

	ft_init_pos(&img);
	img.x2 = (1 - 0) * size.scale;
	img.y2 = (1 + 0) * (size.scale / 2);
	img.x = img.x1;
	while (img.x < img.x2)
	{
		img.y = img.y1 + ((img.y2 - img.y1) * (img.x - img.x1)) / (img.x2 - img.x1);
		ml->data1[img.x + (img.y * size.scale)] = 0x7FDD4C;
		img.x++;
	}
	while (size.x < (size.scale * size.scale))
	{
		if (ml->data1[size.x] != 0x7FDD4C)
			ml->data1[size.x] = 0xFFFFFF64;
		size.x++;
	}
	ft_fill_img2(ml, size);
}

void	ft_fill_img2(t_mlx *ml, t_size size)
{
	t_imgpos	img;

	ft_init_pos(&img);
	img.x2 = (1 - 0) * size.scale;
	img.y2 = (1 + 0) * (size.scale / 2);
	img.x = img.x1;
	while (img.x < img.x2)
	{
		img.y = img.y1 + ((img.y2 - img.y1) * (img.x - img.x1)) / (img.x2 - img.x1);
		ml->data2[img.x + (img.y * size.scale)] = 0x162346;
		img.x++;
	}
	while (size.x < (size.scale * size.scale))
	{
		if (ml->data1[size.x] != 0x162346)
			ml->data1[size.x] = 0xFFFFFF64;
		size.x++;
	}
}
