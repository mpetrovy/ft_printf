/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrovy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 21:44:45 by mpetrovy          #+#    #+#             */
/*   Updated: 2017/12/17 22:24:20 by mpetrovy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	char		*string;
	int			i;
	long int	nn;

	i = -1;
	if ((string = ft_strnew(ft_getleni(n))))
	{
		nn = n;
		if (n < 0)
		{
			string[ft_getleni(n) - 1] = '-';
			nn *= -1;
		}
		if (nn == 0)
			string[++i] = '0';
		else
			while (nn != 0)
			{
				i++;
				string[i] = nn % 10 + '0';
				nn /= 10;
			}
		return (ft_strreverse(string));
	}
	return (NULL);
}
