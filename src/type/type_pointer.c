/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_pointer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrovy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 11:44:11 by mpetrovy          #+#    #+#             */
/*   Updated: 2018/08/24 17:26:13 by mpetrovy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_pointer(t_arg *arg, va_list ap)
{
	char	*nb;
	int		nb_len;
	int		sub;

	arg->flags.l = 1;
	nb = itoa_base(get_number_unsigned(va_arg(ap, void *), &arg->flags), 16, 0);
	nb_len = ft_strlen(nb);
	if (arg->flags.have_precision && !arg->precision && nb[0] == '0')
		nb_len = 0;
	join_precision(arg, nb_len);
	join_args(arg, ft_strdup("0x"), 2, arg->flags.zero == 0);
	sub = nb_len + arg->precision + 2;
	if (!arg->flags.minus)
		join_width(arg, sub, arg->flags.zero == 0);
	join_args(arg, nb, nb_len, NOREVERSE);
	if (arg->flags.minus)
		join_width(arg, sub, NOREVERSE);
}
