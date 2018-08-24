/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_decimal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrovy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 11:45:40 by mpetrovy          #+#    #+#             */
/*   Updated: 2018/08/24 16:40:12 by mpetrovy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_decimal(t_arg *arg, va_list ap)
{
	char	*nb;
	int		nb_len;
	_Bool	have_sign;
	int		sub;

	nb = itoa_base(get_number_signed(va_arg(ap, void *), &arg->flags), 10, 0);
	nb_len = ft_strlen(nb);
	if (arg->flags.have_precision && !arg->precision && nb[0] == '0')
		nb_len = 0;
	have_sign = 0;
	if (arg->flags.negative || arg->flags.plus || arg->flags.space)
		have_sign = 1;
	join_args(arg, get_precision(arg, nb_len), arg->precision, REVERSE);
	join_args(arg, get_sign(arg->flags), have_sign, arg->flags.zero == 0);
	sub = nb_len + arg->precision + have_sign;
	if (!arg->flags.minus)
		join_args(arg, get_width(arg, sub), arg->width, arg->flags.zero == 0);
	join_args(arg, nb, nb_len, NOREVERSE);
	if (arg->flags.minus)
		join_args(arg, get_width(arg, sub), arg->width, NOREVERSE);
	char i = (char)arg->length + 48, j = nb_len + 48;
	write(1, "nb_len[", 7);
	write(1, &j, 1);
	write(1, "]", 1);
	write(1, &i, 1);
}
