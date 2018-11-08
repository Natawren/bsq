/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroelle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:16:56 by jroelle           #+#    #+#             */
/*   Updated: 2018/11/07 19:38:22 by mnarbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

void	ft_fill(int **a, int i, int j, int p)
{
	if (!i && !j)
		a[i][j] = p;
	else if (!i && j)
		a[i][j] = a[i][j - 1] + p;
	else if (i && !j)
		a[i][j] = a[i - 1][j] + p;
	else
		a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + p;
}

int		ft_int_arr(char **arr)
{
	int i;
	int j;
	int **int_arr;

	int_arr = malloc(sizeof(int *) * g_y);
	i = 0;
	while (i < g_y)
	{
		int_arr[i] = malloc(sizeof(int) * g_x);
		j = 0;
		while (j < g_x)
		{
			if (arr[i][j] == g_empty)
				ft_fill(int_arr, i, j, 0);
			else if (arr[i][j] == g_obs)
				ft_fill(int_arr, i, j, 1);
			else
				return (0);
			j++;
		}
		i++;
	}
	ft_make_map(int_arr, arr);
	return (1);
}
