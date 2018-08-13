/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrovy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 17:38:06 by mpetrovy          #+#    #+#             */
/*   Updated: 2017/12/19 18:57:04 by mpetrovy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*s1;

	i = -1;
	s1 = (char *)s;
	while (++i < ft_strlen((char *)s))
		if (*(s1 + i) == c)
			return ((char *)(s + i));
	if (c == 0)
		return ((char *)(s + i));
	return (NULL);
}
