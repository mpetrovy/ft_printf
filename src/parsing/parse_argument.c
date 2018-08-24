/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrovy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 13:15:33 by mpetrovy          #+#    #+#             */
/*   Updated: 2018/08/24 17:56:01 by mpetrovy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		follow_conversion(char c, t_arg *arg, va_list ap, int ret_nb)
{
	if (c == 's' && !arg->flags.l)
		type_string(arg, va_arg(ap, char*));
	else if (c == 'S' || c == 's')
		type_wchar_string(arg, ap);
	else if (c == 'p')
		type_pointer(arg, ap);
	else if (c == 'n')
		type_n(ap, ret_nb);
	else if (c == 'd' || c == 'D' || c == 'i')
		type_decimal(arg, ap);
	else if (c == 'o' || c == 'O')
		type_octal(arg, ap);
	else if (c == 'x' || c == 'X')
		type_hexidecimal(arg, ap, c);
	else if (c == 'u' || c == 'U')
		type_unsigned(arg, ap);
	else if (c == 'c' && !arg->flags.l)
		type_else(arg, (char)va_arg(ap, int));
	else if (c == 'C' || c == 'c')
		type_wchar(arg, va_arg(ap, int));
	else
		type_else(arg, c);
}

void			parse_argument(t_global *global)
{
	t_arg	arg;
	char	*ptr;

	ft_bzero(&arg, sizeof(t_arg));
	parse_flags(global, &arg);
	filtration(&arg, global->format[global->i]);
	if (global->format[global->i] != '\0')
	{
		follow_conversion(global->format[global->i], &arg, global->ap,
						global->ret_nb);
		ptr = ft_memjoin(global->buffer, global->ret_nb, arg.argument,
						arg.length);
		ft_memdel((void**)&global->buffer);
		ft_memdel((void**)&arg.argument);
		global->buffer = ptr;
		global->ret_nb += arg.length;
		global->i++;
	}
}
