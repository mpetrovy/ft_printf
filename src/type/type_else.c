/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_else.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrovy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 11:45:47 by mpetrovy          #+#    #+#             */
/*   Updated: 2018/07/06 23:16:31 by mpetrovy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_else(t_arg *arg, char c)
{
	char	*ptr;

	ptr = NULL;
	if (arg->flags.have_width && --arg->width)
		ptr = ft_memset(malloc(arg->width),
						arg->flags.zero ? '0' : ' ', arg->width);
	if (arg->flags.minus)
		arg->argument = ft_memjoin(&c, 1, ptr, arg->width);
	else
		arg->argument = ft_memjoin(ptr, arg->width, &c, 1);
	arg->length = arg->width + 1;
	ft_memdel((void**)&ptr);
}
