#include <stdio.h>
#include <libft.h>
#include <stdlib.h>
#include <fdf.h>
#include <unistd.h>
#include <fcntl.h>
#include <get_next_line.h>

int		main(int ac, char **av)
{
	int		fd;
	char	*line;

	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line))
	{
		printf("%s\n", line);
		free(line);
	}
	sleep(1000);
	return (0);
}
