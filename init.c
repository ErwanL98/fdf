/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 10:49:11 by ele-cren          #+#    #+#             */
/*   Updated: 2017/02/06 17:03:42 by ele-cren         ###   ########.fr       */
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
}

void	ft_init_args(t_args *ag)
{
	ag->arg1 = "-d";
	ag->arg2 = "-s";
	ag->arg3 = "-b";
}

void	ft_init_colors(t_color *color)
{
	color->colorprev = "0xFFFFFF";
	color->colornext = "0xFFFFFF";
	color->color1hex = "0xFFFFFF";
	color->color2hex = "0xFFFFFF";
	color->color3hex = "0xFFFFFF";
	color->color = 0;
}

void	ft_getz(t_llist *list, t_size *size)
{
	while (list != NULL)
	{
		if (list->z > size->zmax)
			size->zmax = list->z;
		if (list->z < size->zmin)
			size->zmin = list->z;
		if (list->next != NULL)
			list = list->next;
		else
			list = NULL;
	}
}
