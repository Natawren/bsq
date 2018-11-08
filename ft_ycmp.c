/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ycmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroelle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:33:35 by jroelle           #+#    #+#             */
/*   Updated: 2018/11/07 19:31:53 by mnarbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int		ft_ycmp(int y_atoi, t_list *list)
{
	int count;
	int ind;

	count = 0;
	ind = check_ind(list);
	while (list)
	{
		if (list->data[ind] == '\0')
		{
			if (!list->next && (y_atoi != count
				|| list->data[ind - 1] != '\n'))
				return (0);
			else if (!list->next && y_atoi == count)
				return (count);
			ind = -1;
			list = list->next;
		}
		else if (list->data[ind] == '\n')
			count++;
		ind++;
	}
	return (0);
}
