/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrovy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 14:50:52 by mpetrovy          #+#    #+#             */
/*   Updated: 2018/07/06 23:15:44 by mpetrovy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	t_global	global;

	ft_bzero(&global, sizeof(t_global));
	global.format = (char *)format;
	va_start(global.ap, format);
	while (format[global.i] != '\0')
	{
		parsing(&global);
	}
	write(1, global.buffer, global.ret_nb);
	ft_memdel((void**)&global.buffer);
	va_end(global.ap);
	return (global.ret_nb);
}
