/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftstrnstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrovy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 18:29:49 by mpetrovy          #+#    #+#             */
/*   Updated: 2017/12/13 05:08:37 by mpetrovy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *h, const char *n, size_t l)
{
	size_t	needle_len;
	int		len;
	int		i;

	needle_len = ft_strlen((char *)n);
	if (needle_len == 0)
		return ((char *)h);
	len = (int)(l - needle_len);
	i = -1;
	while (*(h + ++i) && len-- >= 0)
		if (!ft_memcmp(h + i, n, needle_len))
			return ((char *)(h + i));
	return (NULL);
}
