/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 15:51:17 by ele-cren          #+#    #+#             */
/*   Updated: 2017/02/13 16:35:08 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <libft.h>
#include <fdf.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int		main(int ac, char **av)
{
	t_size	size;
	t_llist	*list;
	t_args	ag;
	int		i;

	i = 0;
	list = NULL;
	ft_init_args(&ag);
	ft_init_size(&size);
	if (ac < 2 || ac > 8)
	{
		ft_putendl("Arguments missing, or too many arguments.");
		exit(0);
	}
	ft_check_args(av, &size, ag);
	ft_check_valid(av[1], &size);
	list = ft_callread(av[1], size);
	ft_mlx(list, size);
	return (0);
}

void	ft_check_args(char **av, t_size *size, t_args ag)
{
	int		i;

	i = 2;
	while (av[i])
	{
		if (av[i + 1] && ft_atoi(av[i + 1]) <= 0)
			ft_putendl("Error size. Default value was set.");
		else if (ft_strcmp(av[i], ag.arg1) == 0)
			size->deep = (ft_atoi(av[i + 1]) > 0) ? ft_atoi(av[i + 1]) : 1;
		else if (ft_strcmp(av[i], ag.arg2) == 0)
			size->scale = (ft_atoi(av[i + 1]) > 0 && ft_atoi(av[i + 1]) <= 500)\
			? ft_atoi(av[i + 1]) : 20;
		else if (ft_strcmp(av[i], ag.arg3) == 0)
			size->scale2 = (ft_atoi(av[i + 1]) > 0 && ft_atoi(av[i + 1]) <= \
			10) ? ft_atoi(av[i + 1]) : 5;
		else
		{
			ft_putendl("Usage : ./fdf map_file [-s] [-b]");
			exit(1);
		}
		i += 2;
	}
}
