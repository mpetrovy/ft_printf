/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrovy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 17:50:44 by mpetrovy          #+#    #+#             */
/*   Updated: 2017/12/15 15:23:09 by mpetrovy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strreverse(char *s)
{
	int		len;
	char	*s1;
	int		i;

	len = ft_strlen(s);
	s1 = (char *)malloc(sizeof(char) * (len + 1));
	if (!s1)
		return (NULL);
	i = -1;
	while (++i != len)
		*(s1 + i) = *(s + len - i - 1);
	*(s1 + i) = '\0';
	return (s1);
}
