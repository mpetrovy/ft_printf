/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrovy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 12:19:50 by mpetrovy          #+#    #+#             */
/*   Updated: 2018/06/02 14:17:37 by mpetrovy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memjoin(const void *arg1, size_t len1,
					const void *arg2, size_t len2)
{
	unsigned char	*ptr;

	if (arg1 == NULL && arg2 != NULL)
		return (ft_memcpy(malloc(len2), arg2, len2));
	else if (arg2 == NULL && arg1 != NULL)
		return (ft_memcpy(malloc(len1), arg1, len1));
	else if (arg1 == NULL && arg2 == NULL)
		return (0);
	ptr = (unsigned char *)malloc(len1 + len2);
	ft_memcpy(ptr, arg1, len1);
	ft_memcpy(ptr + len1, arg2, len2);
	return ((void *)ptr);
}
