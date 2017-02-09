/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 16:54:54 by ele-cren          #+#    #+#             */
/*   Updated: 2017/02/09 11:08:39 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <libft.h>
#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>

int		ft_key(int keycode, void *param)
{
	(void)*param;
	if (keycode == 53)
		exit(0);
	if (keycode == 123 || keycode == 124)
		ft_move_lr(param, keycode);
	return (0);
}

void	ft_move_lr(t_param *param, int keycode)
{
	if (keycode == 123)
	{
		mlx_clear_window(param->mlx.mlx, param->mlx.win);
		param->size.mvx += 100;
		ft_put(param->list, param->size, param->mlx);
	}
	else
	{
		mlx_clear_window(param->mlx.mlx, param->mlx.win);
		param->size.mvx -= 100;
		ft_put(param->list, param->size, param->mlx);
	}
}
