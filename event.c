/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 16:54:54 by ele-cren          #+#    #+#             */
/*   Updated: 2017/02/06 16:57:07 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <libft.h>
#include <stdlib.h>

int		ft_key(int keycode, void *param)
{
	(void)*param;
	if (keycode == 53)
		exit(0);
	return (0);
}
