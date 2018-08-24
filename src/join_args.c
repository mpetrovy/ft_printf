/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrovy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 10:46:20 by mpetrovy          #+#    #+#             */
/*   Updated: 2018/08/24 16:49:20 by mpetrovy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	join_args(t_arg *arg, char *str, int len, _Bool reverse)
{
	char	*temp;

	if (arg->a)
	{
		char j = len + 48;
		write(1, "join[", 5);
		write(1, &j, 1);
		write(1, "]", 1);
		arg->a = 0;

	}
	temp = arg->argument;
	if (reverse)
		arg->argument = ft_memjoin(str, len, arg->argument, arg->length);
	else
		arg->argument = ft_memjoin(arg->argument, arg->length, str, len);
	arg->length += len;
	ft_memdel((void**)&temp);
	ft_memdel((void**)&str);
}
