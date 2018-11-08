/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroelle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 12:56:57 by jroelle           #+#    #+#             */
/*   Updated: 2018/10/31 21:29:38 by jroelle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

void	ft_list_clear(t_list **begin_list)
{
	t_list *t;

	while (*begin_list)
	{
		t = *begin_list;
		*begin_list = (*begin_list)->next;
		free(t);
	}
	*begin_list = NULL;
}
