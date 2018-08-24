/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrovy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 14:56:39 by mpetrovy          #+#    #+#             */
/*   Updated: 2018/08/24 16:52:25 by mpetrovy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_wchar_len(int wchar)
{
	if (wchar < 0x80)
		return (1);
	else if (wchar >= 0x80 && wchar < 0x800)
		return (2);
	else if (wchar >= 0x800 && wchar < 0x10000)
		return (3);
	return (4);
}

char	*get_wchar(int wchar, int len)
{
	char	*str;

	str = (char*)malloc(len);
	if (len == 1)
		str[0] = (char)wchar;
	else
	{
		str[0] = (char)((wchar >> (6 * (len - 1))) | (240 << (4 - len)));
		while (--len)
		{
			str[len] = (wchar & 077) | 0200;
			wchar >>= 6;
		}
	}
	return (str);
}

char	*get_width(t_arg *arg, int sub)
{
	if (arg->flags.have_width)
	{
		arg->width -= sub;
		if (arg->width > 0)
		{
			return (ft_memset(malloc(arg->width),
							arg->flags.zero ? '0' : ' ', arg->width));
		}
		arg->width = 0;
	}
	return (NULL);
}

char	*get_sign(t_flags flags)
{
	if (flags.negative)
		return (ft_memset(malloc(1), '-', 1));
	else if (flags.plus)
		return (ft_memset(malloc(1), '+', 1));
	else if (flags.space)
		return (ft_memset(malloc(1), ' ', 1));
	return (NULL);
}

char	*get_precision(t_arg *arg, int nb_len)
{
	if (arg->flags.have_precision)
	{
		arg->precision -= nb_len;
		if (arg->precision > 0)
		{
			return (ft_memset(malloc(arg->precision), '0', arg->precision));
		}
		arg->precision = 0;
	}
	return (NULL);
}
