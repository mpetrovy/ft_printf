/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrovy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 17:49:08 by mpetrovy          #+#    #+#             */
/*   Updated: 2017/12/13 05:12:27 by mpetrovy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ref;

	ref = (char *)s;
	i = ft_strlen((char *)s) + 1;
	while (--i != -1)
		if (*(ref + i) == c)
			return (ref + i);
	return (NULL);
}
