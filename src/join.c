/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrovy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 17:00:08 by mpetrovy          #+#    #+#             */
/*   Updated: 2018/08/24 17:33:56 by mpetrovy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	join_precision(t_arg *arg, int nb_len)
{
	char	*temp;

	temp = get_precision(arg, nb_len);
	join_args(arg, temp, arg->precision, REVERSE);
}

void	join_width(t_arg *arg, int sub, _Bool flag)
{
	char	*temp;

	temp = get_width(arg, sub);
	join_args(arg, temp, arg->width, flag);
}

void	join_args(t_arg *arg, char *str, int len, _Bool reverse)
{
	char	*temp;

	temp = arg->argument;
	if (reverse)
		arg->argument = ft_memjoin(str, len, arg->argument, arg->length);
	else
		arg->argument = ft_memjoin(arg->argument, arg->length, str, len);
	arg->length += len;
	ft_memdel((void**)&temp);
	ft_memdel((void**)&str);
}
