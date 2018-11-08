/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_symbol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroelle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:25:10 by jroelle           #+#    #+#             */
/*   Updated: 2018/11/07 20:32:28 by jroelle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int		ft_check_invalid_args(int n, t_list **begin_list)
{
	int i;

	i = 0;
	while (((*begin_list)->data[i] == ' ' || (*begin_list)->data[i] == '+'
			|| ((*begin_list)->data[i] >= '0' && (*begin_list)->data[i] <= '9'))
			&& (*begin_list)->data[i] != '\n')
		i++;
	if (n - i == 3)
		return (1);
	return (0);
}

int		ft_init_symbol(t_list **begin_list)
{
	int	i;

	i = 0;
	while ((*begin_list)->data[i] != '\n' && (*begin_list)->data[i])
		i++;
	if (i < 4)
		return (0);
	g_empty = (*begin_list)->data[i - 3];
	g_obs = (*begin_list)->data[i - 2];
	g_full = (*begin_list)->data[i - 1];
	if (g_empty == g_obs || g_empty == g_full || g_full == g_obs
			|| g_empty == '\n' || g_obs == '\n' || g_full == '\n')
		return (0);
	(*begin_list)->data[i - 3] = '.';
	if (!ft_check_invalid_args(i, begin_list))
		return (0);
	return (1);
}
