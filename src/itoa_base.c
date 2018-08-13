/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrovy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 17:43:19 by mpetrovy          #+#    #+#             */
/*   Updated: 2018/06/16 18:12:36 by mpetrovy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define VALUE 0
#define BASE 1

static void	recursion(char *str, int *i, unsigned long itoa[], char hex)
{
	char			*small;
	char			*large;
	unsigned long	value;

	large = "0123456789ABCDEF";
	small = "0123456789abcdef";
	value = itoa[VALUE];
	if (itoa[VALUE] >= itoa[BASE])
	{
		itoa[VALUE] = itoa[VALUE] / itoa[BASE];
		recursion(str, i, itoa, hex);
	}
	str[(*i)++] = hex == 'X' ? large[(value % itoa[BASE])] :
		small[(value % itoa[BASE])];
}

char		*itoa_base(unsigned long value, unsigned int base, char hex)
{
	unsigned long	itoa[2];
	int				i;
	char			*str;

	i = 0;
	itoa[VALUE] = value;
	itoa[BASE] = base;
	str = (char *)malloc(32);
	recursion(str, &i, itoa, hex);
	str[i] = '\0';
	return (str);
}
