/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrovy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 19:38:12 by mpetrovy          #+#    #+#             */
/*   Updated: 2017/12/19 19:15:32 by mpetrovy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*s1;
	int		i;

	if (!s || !f)
		return (NULL);
	s1 = (char *)ft_memalloc(ft_strlen((char *)s) + 1);
	if (!s1)
		return (NULL);
	i = -1;
	while (*(s + ++i))
		*(s1 + i) = f(i, *(s + i));
	*(s1 + i) = '\0';
	return (s1);
}
