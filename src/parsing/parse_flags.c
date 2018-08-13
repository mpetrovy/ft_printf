/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrovy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 13:15:49 by mpetrovy          #+#    #+#             */
/*   Updated: 2018/06/02 14:23:32 by mpetrovy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static _Bool	is_flag(char c)
{
	return (!(c != '#' && c != ' ' && c != 'h' && c != '+' && c != '-' &&
			c != 'l' && c != 'j' && c != 'z' && !ft_isdigit(c) && c != '.'));
}

static _Bool	is_bool_flag(char c)
{
	return (!(c != '#' && c != ' ' && c != 'h' && c != '+' && c != '-' &&
			c != 'l' && c != 'j' && c != 'z' && c != '0'));
}

static void		set_bool_flag(t_arg *arg, char c)
{
	if (c == '#')
		arg->flags.hash = 1;
	else if (c == '0')
		arg->flags.zero = 1;
	else if (c == '-')
		arg->flags.minus = 1;
	else if (c == '+')
		arg->flags.plus = 1;
	else if (c == ' ')
		arg->flags.space = 1;
	else if (c == 'h')
		arg->h_counter++;
	else if (c == 'l')
		arg->l_counter++;
	else if (c == 'j')
		arg->flags.j = 1;
	else
		arg->flags.z = 1;
}

static void		set_width_or_precision(t_arg *arg, char *format, int *i)
{
	size_t		nb;
	_Bool		is_dot;

	nb = 0;
	if ((is_dot = format[*i] == '.'))
	{
		arg->flags.have_precision = 1;
		(*i)++;
		while (format[*i] == '0')
			(*i)++;
	}
	while (ft_isdigit(format[*i]))
	{
		nb = nb * 10 + (format[*i] - 48);
		(*i)++;
	}
	if (is_dot)
		arg->precision = (int)nb;
	else
	{
		arg->flags.have_width = 1;
		arg->width = (int)nb;
	}
}

void			parse_flags(t_global *global, t_arg *arg)
{
	while (is_flag(global->format[global->i]))
	{
		if (is_bool_flag(global->format[global->i]))
		{
			set_bool_flag(arg, global->format[global->i]);
			global->i++;
		}
		else
			set_width_or_precision(arg, global->format, &global->i);
	}
}
