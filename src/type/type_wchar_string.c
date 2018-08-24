/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_wchar_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrovy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 11:44:09 by mpetrovy          #+#    #+#             */
/*   Updated: 2018/08/24 17:31:17 by mpetrovy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	apply_precision(int *wchar, t_arg *arg)
{
	int		i;
	int		wchar_len;

	i = 0;
	while (wchar[i])
	{
		wchar_len = get_wchar_len(wchar[i]);
		if (arg->flags.have_precision &&
			arg->length + wchar_len > arg->precision)
		{
			break ;
		}
		join_args(arg, get_wchar(wchar[i], wchar_len), wchar_len, NOREVERSE);
		i++;
	}
}

void		type_wchar_string(t_arg *arg, va_list ap)
{
	int		*wchar;

	if ((wchar = va_arg(ap, int*)) == NULL)
		type_string(arg, "(null)");
	else
	{
		apply_precision(wchar, arg);
		join_width(arg, arg->length, arg->flags.minus == 0);
	}
}
