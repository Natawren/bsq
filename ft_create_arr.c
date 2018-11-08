/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroelle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 16:31:04 by jroelle           #+#    #+#             */
/*   Updated: 2018/11/07 19:37:20 by mnarbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int		check_ind(t_list *list)
{
	int ind;

	ind = 0;
	if (list->data[ind] == '+' && list->data[ind])
		ind++;
	while (list->data[ind] != '\n' && list->data[ind])
		ind++;
	ind++;
	return (ind);
}

int		ft_check_str(t_list *list)
{
	int ind;
	int x;
	int temp;
	int f;

	f = 0;
	temp = 0;
	ind = check_ind(list);
	while (list)
	{
		ft_xcmp(&ind, &x, &list);
		if (list->data[ind] == '\n')
		{
			ind++;
			if (!f++)
				temp = x;
		}
		if (list->data[ind] == '\0' && !list->next && temp == x)
			return (x);
		if (temp != x)
			return (0);
	}
	return (0);
}

void	ft_check_list(t_list **list, int *ind)
{
	int f;

	f = 0;
	if ((*list)->data[(*ind)] == '\n')
	{
		(*ind)++;
		f = 1;
	}
	if ((*list)->data[(*ind)] == '\0')
	{
		*ind = 0;
		*list = (*list)->next;
	}
	if ((*list)->data[(*ind)] == '\n' && !f)
		(*ind)++;
}

char	**ft_create_arr(t_list *list)
{
	int		i;
	int		j;
	int		ind;
	char	**arr;

	ind = check_ind(list);
	g_y = ft_ycmp(ft_atoi(list->data, &list), list);
	arr = malloc(sizeof(char *) * g_y);
	i = 0;
	if (!g_y || !(g_x = ft_check_str(list)))
		return (NULL);
	while (i < g_y)
	{
		arr[i] = malloc(sizeof(char) * g_x);
		j = 0;
		while (j < g_x && list)
		{
			ft_check_list(&list, &ind);
			arr[i][j] = list->data[ind++];
			j++;
		}
		i++;
	}
	return (arr);
}
