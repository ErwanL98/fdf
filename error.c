/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 17:36:29 by ele-cren          #+#    #+#             */
/*   Updated: 2017/02/13 14:39:13 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>
#include <stdlib.h>
#include <fdf.h>
#include <fcntl.h>
#include <unistd.h>
#include <get_next_line.h>

void	ft_error_map(void)
{
	ft_putendl("\x1b[31m       -----------------------------------------");
	ft_putendl("      |               INVALID MAP               |");
	ft_putendl("       -----------------------------------------");
	ft_putendl("\x1b[32m                  EXAMPLE OF VALID MAP     \x1b[0m");
	ft_putendl(" 0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0 \n \
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0\n \
0  0 10 10  0  0 10 10  0  0  0 10 10 10 10 10  0  0  0\n \
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0\n \
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0\n \
0  0 10 10 10 10 10 10  0  0  0  0 10 10 10 10  0  0  0\n \
0  0  0 10 10 10 10 10  0  0  0 10 10  0  0  0  0  0  0\n \
0  0  0  0  0  0 10 10  0  0  0 10 10  0  0  0  0  0  0\n \
0  0  0  0  0  0 10 10  0  0  0 10 10 10 10 10 10  0  0\n \
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0\n \
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0");
	exit(1);
}

void	ft_error_file(void)
{
	perror("Error : ");
	exit(1);
}

void	ft_check_valid(char *av, t_size *size)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	if ((fd = open(av, O_RDONLY)) == -1)
		ft_error_file();
	while (get_next_line(fd, &line))
	{
		i = ft_count_words(line, ' ');
		if ((size->nbcoor != 0 && i != size->nbcoor) || i == 0)
			ft_error_map();
		size->nbcoor = i;
		size->nbline++;
		free(line);
	}
	if (size->nbline > 40 || size->nbcoor > 70)
		size->scale = size->scale2;
	if ((close(fd)) == -1)
		ft_error_file();
}
