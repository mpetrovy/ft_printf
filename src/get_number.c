/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrovy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 14:59:23 by mpetrovy          #+#    #+#             */
/*   Updated: 2018/08/12 14:59:54 by mpetrovy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long	get_number_unsigned(void *nb, t_flags *flags)
{
	unsigned long	chiselko;

	if (flags->z || flags->j || flags->ll || flags->l)
		chiselko = (unsigned long)nb;
	else if (flags->h)
		chiselko = (unsigned short)nb;
	else if (flags->hh)
		chiselko = (unsigned char)nb;
	else
		chiselko = (unsigned int)nb;
	return ((unsigned long)chiselko);
}

unsigned long	get_number_signed(void *nb, t_flags *flags)
{
	long	chiselko;

	if (flags->z || flags->j || flags->ll || flags->l)
		chiselko = (long)nb;
	else if (flags->h)
		chiselko = (short)nb;
	else if (flags->hh)
		chiselko = (char)nb;
	else
		chiselko = (int)nb;
	flags->negative = chiselko < 0;
	return ((unsigned long)(chiselko < 0 ? -chiselko : chiselko));
}
