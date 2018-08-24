/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_octal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrovy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 11:45:47 by mpetrovy          #+#    #+#             */
/*   Updated: 2018/08/24 17:25:26 by mpetrovy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_hash(t_flags flags)
{
	if (flags.hash)
		return (ft_memset(malloc(1), '0', 1));
	return (NULL);
}

void		type_octal(t_arg *arg, va_list ap)
{
	char	*nb;
	int		nb_len;
	_Bool	have_hash;
	int		sub;

	nb = itoa_base(get_number_unsigned(va_arg(ap, void *), &arg->flags), 8, 0);
	nb_len = ft_strlen(nb);
	if (((arg->flags.have_precision && !arg->precision && !arg->flags.hash) ||
		arg->flags.hash) && nb[0] == '0')
		nb_len = 0;
	have_hash = 0;
	if (arg->flags.hash)
		have_hash = 1;
	join_precision(arg, nb_len + have_hash);
	join_args(arg, get_hash(arg->flags), have_hash, arg->flags.zero == 0);
	sub = nb_len + arg->precision + have_hash;
	if (!arg->flags.minus)
		join_width(arg, sub, arg->flags.zero == 0);
	join_args(arg, nb, nb_len, NOREVERSE);
	if (arg->flags.minus)
		join_width(arg, sub, NOREVERSE);
}
