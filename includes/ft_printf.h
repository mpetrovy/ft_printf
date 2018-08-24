/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrovy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 14:12:04 by mpetrovy          #+#    #+#             */
/*   Updated: 2018/08/24 17:43:53 by mpetrovy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# define NOREVERSE 0
# define REVERSE 1

typedef struct s_flags	t_flags;
typedef struct s_arg	t_arg;
typedef struct s_global	t_global;

struct			s_flags
{
	unsigned int		hash : 1;
	unsigned int		zero : 1;
	unsigned int		minus : 1;
	unsigned int		plus : 1;
	unsigned int		space : 1;
	unsigned int		have_precision : 1;
	unsigned int		have_width : 1;
	unsigned int		negative : 1;
	unsigned int		hh : 1;
	unsigned int		h : 1;
	unsigned int		l : 1;
	unsigned int		ll : 1;
	unsigned int		j : 1;
	unsigned int		z : 1;
};

struct			s_arg
{
	char	*argument;
	int		length;
	int		h_counter;
	int		l_counter;
	int		precision;
	int		width;
	t_flags	flags;
};

struct			s_global
{
	char	*format;
	int		i;
	va_list	ap;
	char	*buffer;
	int		ret_nb;
};

int				ft_printf(const char *format, ...);
void			parsing(t_global *global);
void			parse_flags(t_global *global, t_arg *arg);
void			parse_argument(t_global *global);
void			filtration(t_arg *arg, char c);

void			type_string(t_arg *arg, char *str);
void			type_wchar_string(t_arg *arg, va_list ap);
void			type_pointer(t_arg *arg, va_list ap);
void			type_char(t_arg *arg, va_list ap);
void			type_wchar(t_arg *arg, int wchar);

void			type_decimal(t_arg *arg, va_list ap);
void			type_unsigned(t_arg *arg, va_list ap);
void			type_hexidecimal(t_arg *arg, va_list ap, char c);
void			type_octal(t_arg *arg, va_list ap);
void			type_else(t_arg *arg, char c);
void			type_n(va_list ap, int ret_nb);

char			*itoa_base(unsigned long value, unsigned int base, char hex);

void			join_args(t_arg *arg, char *str, int len, _Bool reverse);
void			join_precision(t_arg *arg, int nb_len);
void			join_width(t_arg *arg, int sub, _Bool flag);

unsigned long	get_number_signed(void *nb, t_flags *flags);
unsigned long	get_number_unsigned(void *nb, t_flags *flags);
char			*get_width(t_arg *arg, int sub);
char			*get_sign(t_flags flags);
char			*get_precision(t_arg *arg, int nb_len);
int				get_wchar_len(int wchar);
char			*get_wchar(int wchar, int len);

#endif
