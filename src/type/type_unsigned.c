/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_unsigned.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrovy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 11:45:46 by mpetrovy          #+#    #+#             */
/*   Updated: 2018/08/24 17:29:18 by mpetrovy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_unsigned(t_arg *arg, va_list ap)
{
	char	*nb;
	int		nb_len;
	int		sub;

	nb = itoa_base(get_number_unsigned(va_arg(ap, void *), &arg->flags), 10, 0);
	nb_len = ft_strlen(nb);
	if (arg->flags.have_precision && !arg->precision && nb[0] == '0')
		nb_len = 0;
	join_precision(arg, nb_len);
	sub = nb_len + arg->precision;
	if (!arg->flags.minus)
		join_width(arg, sub, REVERSE);
	join_args(arg, nb, nb_len, NOREVERSE);
	if (arg->flags.minus)
		join_width(arg, sub, NOREVERSE);
}
