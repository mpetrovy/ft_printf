/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrovy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 16:37:42 by mpetrovy          #+#    #+#             */
/*   Updated: 2017/12/13 04:11:26 by mpetrovy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				i;
	unsigned char	*si1;
	unsigned char	*si2;

	i = -1;
	si1 = (unsigned char *)s1;
	si2 = (unsigned char *)s2;
	while (++i < (int)n)
		if (*(si1 + i) != *(si2 + i))
			return (*(si1 + i) - *(si2 + i));
	return (0);
}
