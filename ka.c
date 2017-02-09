#include <stdio.h>
#include <libft.h>
#include <fdf.h>

int		main(void)
{
	char	*str;
	t_rgba	rgba;

	str = "0xFF000064";
	rgba = ft_hex_to_rgba(str);
	printf("r:%f\ng:%f\nb:%f\na:%f\n", rgba.r, rgba.g, rgba.b, rgba.a);
	return (0);
}
