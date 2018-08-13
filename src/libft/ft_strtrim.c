/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrovy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 20:32:55 by mpetrovy          #+#    #+#             */
/*   Updated: 2017/12/19 19:26:29 by mpetrovy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	char	*s1;
	char	*s2;

	if (!s)
		return (NULL);
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	s1 = (char *)ft_memalloc(ft_strlen((char *)s) + 1);
	if (!s1)
		return (NULL);
	s1 = ft_strreverse((char *)s);
	while (*s1 == ' ' || *s1 == '\n' || *s1 == '\t')
		s1++;
	s2 = (char *)ft_memalloc(ft_strlen((char *)s1) + 1);
	s2 = ft_strreverse(s1);
	return (s2);
}
