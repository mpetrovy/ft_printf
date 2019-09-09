/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabsymb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrovy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:08:40 by mpetrovy          #+#    #+#             */
/*   Updated: 2017/11/20 15:59:55 by mpetrovy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_tabsymb(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || \
		c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}
