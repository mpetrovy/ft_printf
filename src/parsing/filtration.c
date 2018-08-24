/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filtration.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrovy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 18:27:48 by mpetrovy          #+#    #+#             */
/*   Updated: 2018/08/24 17:39:36 by mpetrovy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	filtration(t_arg *arg, char c)
{
	if (arg->h_counter && arg->h_counter % 2 == 1)
		arg->flags.h = 1;
	else if (arg->h_counter)
		arg->flags.hh = 1;
	if ((arg->l_counter && arg->l_counter % 2 == 1) ||
		c == 'S' || c == 'D' || c == 'O' || c == 'U')
		arg->flags.l = 1;
	else if (arg->l_counter)
		arg->flags.ll = 1;
	if (arg->flags.plus == 1)
		arg->flags.space = 0;
	if (((c == 'd' || c == 'p' ||
		c == 'D' || c == 'i' || c == 'o' || c == 'O' || c == 'x' ||
		c == 'X' || c == 'u' || c == 'U') && arg->flags.have_precision) ||
		arg->flags.minus == 1)
		arg->flags.zero = 0;
}
