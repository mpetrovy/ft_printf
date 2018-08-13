/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_wchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrovy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 11:44:12 by mpetrovy          #+#    #+#             */
/*   Updated: 2018/08/12 17:44:10 by mpetrovy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_wchar(t_arg *arg, int wchar)
{
	int		wchar_len;

	wchar_len = get_wchar_len(wchar);
	if (!arg->flags.minus)
		join_args(arg, get_width(arg, wchar_len), arg->width, REVERSE);
	join_args(arg, get_wchar(wchar, wchar_len), wchar_len, NOREVERSE);
	if (arg->flags.minus)
		join_args(arg, get_width(arg, wchar_len), arg->width, NOREVERSE);
}
