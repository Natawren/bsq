/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xcmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroelle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:40:45 by jroelle           #+#    #+#             */
/*   Updated: 2018/11/07 19:33:02 by mnarbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

void	ft_xcmp(int *ind, int *x, t_list **list)
{
	*x = 0;
	while ((*list)->data[*ind] != '\n')
	{
		if ((*list)->data[*ind] == '\0' && (*list)->next)
		{
			*ind = 0;
			*list = (*list)->next;
		}
		else
		{
			(*x)++;
			(*ind)++;
		}
	}
}
