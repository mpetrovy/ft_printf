/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrovy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 10:46:20 by mpetrovy          #+#    #+#             */
/*   Updated: 2018/07/15 10:46:53 by mpetrovy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
