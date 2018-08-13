/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrovy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 10:06:17 by mpetrovy          #+#    #+#             */
/*   Updated: 2017/12/13 04:35:58 by mpetrovy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void				*ft_memset(void *dest, int c, size_t n)
{
	int				i;
	unsigned char	*back;

	i = -1;
	back = (unsigned char *)dest;
	while (++i < (int)n)
		*(back + i) = (unsigned char)c;
	return (dest);
}
