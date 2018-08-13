/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrovy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 16:23:55 by mpetrovy          #+#    #+#             */
/*   Updated: 2017/12/13 03:51:35 by mpetrovy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void				*ft_memchr(const void *s, int c, size_t n)
{
	int				i;
	unsigned char	*s1;

	i = -1;
	s1 = (unsigned char *)s;
	while (++i < (int)n)
		if (s1[i] == (unsigned char)c)
			return ((void *)(s1 + i));
	return (NULL);
}
