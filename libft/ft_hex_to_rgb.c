/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_to_rgb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 10:46:14 by ele-cren          #+#    #+#             */
/*   Updated: 2017/02/09 11:06:58 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>
#include <libft.h>

t_rgb	ft_hex_to_rgb(char *color)
{
	int		i;
	char	**tab;
	t_rgb	rgb;
	int		j;
	int		k;

	k = 0;
	if (ft_strlen(color) < 6 && ft_strlen(color) > 8)
		exit(1);
	if ((tab = (char **)malloc(sizeof(char *) * 4)) == NULL)
		exit(0);
	i = (color[1] == 'x') ? 2 : 0;
	while (color[i])
	{
		tab[k] = ft_strnew(2);
		j = -1;
		while (++j < 2)
			tab[k][j] = color[i++];
		k++;
	}
	rgb.r = (tab[0]) ? ft_hex_to_dec(tab[0]) : 0;
	rgb.g = (tab[1]) ? ft_hex_to_dec(tab[1]) : 0;
	rgb.b = (tab[2]) ? ft_hex_to_dec(tab[2]) : 0;
	return (rgb);
}
