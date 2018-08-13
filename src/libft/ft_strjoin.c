/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrovy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 20:17:57 by mpetrovy          #+#    #+#             */
/*   Updated: 2017/12/13 06:48:44 by mpetrovy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;

	if (!s1 || !s2)
		return (NULL);
	string = (char *)malloc(sizeof(char) * (ft_strlen((char *)s1) +
											ft_strlen((char *)s2) + 1));
	if (!string)
		return (NULL);
	ft_strcpy(string, (char *)s1);
	ft_strcpy(string + ft_strlen((char *)s1), (char *)s2);
	return (string);
}
