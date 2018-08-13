/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrovy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 19:48:09 by mpetrovy          #+#    #+#             */
/*   Updated: 2017/12/19 19:23:06 by mpetrovy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s1;
	int		i;

	if (!s || (size_t)start + len > ft_strlen((char *)s) ||
		(int)len < 0)
		return (NULL);
	if ((s1 = ft_strnew(len)))
	{
		i = -1;
		while (++i < (int)len)
			s1[i] = s[start + i];
		s1[i] = '\0';
	}
	return (s1);
}
