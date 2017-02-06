/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 10:49:24 by ele-cren          #+#    #+#             */
/*   Updated: 2017/02/03 10:45:44 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void	ft_itoaneg(int *neg, int *n)
{
	if (*n < 0)
	{
		*n = -*n;
		*neg = 1;
	}
}

char	*ft_itoa(int n)
{
	int		neg;
	char	*str;
	int		i;


	str = NULL;
	neg = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = ft_nbrlen(n) + 1;
	ft_itoaneg(&neg, &n);
	i += neg;
	if ((str = ft_strnew(i - 1)) == NULL)
		return (NULL);
	--i;
	while (i--)
	{
		str[i] = n % 10 + '0';
		n /= 10;
	}
	if (neg != 0)
		str[0] = '-';
	return (str);
}
