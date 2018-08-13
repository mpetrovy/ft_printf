/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrovy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 17:27:50 by mpetrovy          #+#    #+#             */
/*   Updated: 2017/12/13 01:16:21 by mpetrovy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	int		n;

	dstlen = ft_strlen((char *)dst);
	srclen = ft_strlen((char *)src);
	if ((n = (int)dstsize - (int)dstlen) <= 0)
		return (srclen + dstsize);
	dst += dstlen;
	while (*src && n-- > 1)
		*dst++ = *src++;
	*dst = '\0';
	return (dstlen + srclen);
}
