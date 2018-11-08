/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroelle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 15:03:39 by jroelle           #+#    #+#             */
/*   Updated: 2018/11/07 22:17:47 by jroelle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int	ft_atoi(char *str, t_list **list)
{
	int		r;
	int		zn;

	if (!ft_init_symbol(list))
		return (0);
	zn = 1;
	while (*str == ' ')
		str++;
	if (*str == '+')
		str++;
	if (*str == '-')
	{
		zn = -1;
		str++;
	}
	r = 0;
	while (*str >= '0' && *str <= '9' && *str)
	{
		r = r * 10 + *str - '0';
		str++;
	}
	return (zn * r);
}
