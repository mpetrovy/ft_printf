/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrovy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 11:42:01 by mpetrovy          #+#    #+#             */
/*   Updated: 2018/08/13 21:23:07 by mpetrovy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_string(t_arg *arg, char *str)
{
	int		len;

	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	if (arg->flags.have_precision && len && len > arg->precision)
		len = arg->precision;
	join_args(arg, ft_strdup(str), len, NOREVERSE);
	join_args(arg, get_width(arg, len), arg->width, arg->flags.minus == 0);
}
