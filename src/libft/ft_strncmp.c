/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrovy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 23:47:02 by mpetrovy          #+#    #+#             */
/*   Updated: 2017/12/13 04:58:48 by mpetrovy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n--)
	{
		if (*s1 != *s2++)
			return ((*(unsigned char *)s1 - *(unsigned char *)--s2));
		if (*s1++ == '\0')
			return (0);
	}
	return (0);
}
