/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrovy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 15:59:59 by mpetrovy          #+#    #+#             */
/*   Updated: 2017/12/17 14:38:26 by mpetrovy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	int		i;
	char	*pointer;
	size_t	len;

	len = ft_strlen(src);
	if ((pointer = ft_strnew(len)))
	{
		i = 0;
		while (src[i])
		{
			pointer[i] = src[i];
			i++;
		}
		pointer[i] = '\0';
	}
	return (pointer);
}
