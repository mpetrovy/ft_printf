/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrovy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 15:21:15 by mpetrovy          #+#    #+#             */
/*   Updated: 2017/12/13 05:16:46 by mpetrovy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *hay, const char *n)
{
	size_t	needle_len;
	int		i;

	needle_len = ft_strlen((char *)n);
	if (needle_len == 0)
		return ((char *)hay);
	i = -1;
	hay = ft_strchr(hay, *n);
	if (!hay)
		return (NULL);
	while (*(hay + ++i))
		if (!ft_memcmp(hay + i, n, needle_len))
			return ((char *)(hay + i));
	return (NULL);
}
