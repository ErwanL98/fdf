/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isescape.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 10:48:31 by ele-cren          #+#    #+#             */
/*   Updated: 2016/11/18 10:50:55 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isescape(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\r' || \
			c == '\f')
		return (1);
	else
		return (0);
}
