/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrovy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 12:04:50 by mpetrovy          #+#    #+#             */
/*   Updated: 2018/07/06 23:17:57 by mpetrovy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		count_part_len(char *format, int i)
{
	int	len;

	len = i;
	while (format[len] && format[len] != '%')
		len++;
	return (len - i);
}

static char		*join_buffer(t_global *global, int part_len)
{
	char	*new_buf;

	new_buf = (char *)malloc(global->ret_nb + part_len);
	if (!new_buf)
		exit(1);
	ft_memcpy(new_buf, global->buffer, global->ret_nb);
	ft_memcpy(new_buf + global->ret_nb,
			global->format + global->i, part_len);
	return (new_buf);
}

void			parsing(t_global *global)
{
	int		part_len;
	char	*prev_buf;

	if (global->format[global->i] == '%')
	{
		global->i++;
		parse_argument(global);
	}
	else
	{
		part_len = count_part_len(global->format, global->i);
		prev_buf = global->buffer;
		global->buffer = join_buffer(global, part_len);
		ft_memdel((void**)&prev_buf);
		global->i += part_len;
		global->ret_nb += part_len;
	}
}
