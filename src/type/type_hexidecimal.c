/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_hexidecimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrovy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 11:45:47 by mpetrovy          #+#    #+#             */
/*   Updated: 2018/08/24 17:23:57 by mpetrovy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_hash(t_flags flags, char c)
{
	if (flags.hash)
		return (ft_strdup(c == 'X' ? "0X" : "0x"));
	return (NULL);
}

void		type_hexidecimal(t_arg *arg, va_list ap, char c)
{
	char	*nb;
	int		nb_len;
	_Bool	have_hash;
	int		sub;

	nb = itoa_base(get_number_unsigned(va_arg(ap, void *), &arg->flags), 16, c);
	nb_len = ft_strlen(nb);
	if (arg->flags.have_precision && !arg->precision && nb[0] == '0')
		nb_len = 0;
	have_hash = 0;
	if (arg->flags.hash && nb[0] != '0')
		have_hash = 1;
	join_precision(arg, nb_len);
	join_args(arg, get_hash(arg->flags, c), have_hash ? 2 : 0,
			arg->flags.zero == 0);
	sub = nb_len + arg->precision + (have_hash ? 2 : 0);
	if (!arg->flags.minus)
		join_width(arg, sub, arg->flags.zero == 0);
	join_args(arg, nb, nb_len, NOREVERSE);
	if (arg->flags.minus)
		join_width(arg, sub, NOREVERSE);
}
