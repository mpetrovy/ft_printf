/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_n.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrovy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 17:40:45 by mpetrovy          #+#    #+#             */
/*   Updated: 2018/08/24 17:46:49 by mpetrovy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_n(va_list ap, int ret_nb)
{
	int	*n;

	n = va_arg(ap, int*);
	*n = ret_nb;
}
