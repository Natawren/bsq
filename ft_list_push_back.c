/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroelle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 11:09:06 by jroelle           #+#    #+#             */
/*   Updated: 2018/11/04 16:06:53 by jroelle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

void	ft_list_push_back(t_list **begin_list, char *data)
{
	t_list *l;
	t_list *q;

	l = ft_create_elem(data);
	q = *begin_list;
	if (q)
	{
		while (q->next)
			q = q->next;
		q->next = l;
	}
	else
		*begin_list = l;
}
