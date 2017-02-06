/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 14:15:39 by ele-cren          #+#    #+#             */
/*   Updated: 2017/02/01 17:55:53 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libft.h>
#include <stdlib.h>
#include <stdio.h>

static int		ft_count_length(const char *s, int i, char c)
{
	int		j;

	j = i;
	while (s[j] != c && s[j] != '\0')
		j++;
	return (j - i);
}

static char		**ft_create(char **tab, const char *s, char c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (i < ft_count_words(s, c))
	{
		k = 0;
		tab[i] = ft_strnew(ft_count_length(s, j, c));
		if (!tab[i])
			return (NULL);
		while (s[j] == c && s[j] != '\0')
			j++;
		while (s[j] != c && s[j] != '\0')
		{
			tab[i][k] = s[j];
			k++;
			j++;
		}
		tab[i][k] = '\0';
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;

	if (s)
	{
		tab = (char **)malloc(sizeof(char *) * ft_count_words(s, c) + 1);
		if (!tab)
			return (NULL);
		tab = ft_create(tab, s, c);
		return (tab);
	}
	return (NULL);
}
