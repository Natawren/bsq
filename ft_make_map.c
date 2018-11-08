/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroelle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:06:38 by jroelle           #+#    #+#             */
/*   Updated: 2018/11/07 11:08:28 by mnarbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

void	ft_print_arr(char **arr, int imax, int jmax, int max)
{
	int i;
	int j;

	i = 0;
	while (i < g_y)
	{
		j = 0;
		while (j < g_x)
		{
			if (i <= imax && i >= imax - max + 1
				&& j <= jmax && j >= jmax - max + 1)
				write(1, &g_full, 1);
			else
				write(1, &arr[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int		ft_check_square(int **int_arr, int i, int j, int edge)
{
	int b;
	int c;
	int d;

	if (j - edge < 0)
		b = 0;
	else
		b = int_arr[i][j - edge];
	if (i - edge < 0)
		c = 0;
	else
		c = int_arr[i - edge][j];
	if (i - edge < 0 || j - edge < 0)
		d = 0;
	else
		d = int_arr[i - edge][j - edge];
	return (int_arr[i][j] - b - c + d);
}

void	ft_make_map(int **int_arr, char **arr)
{
	int i;
	int j;
	int ijemax[4];

	i = 0;
	ijemax[3] = 1;
	ijemax[2] = 1;
	while (i < g_y)
	{
		j = ijemax[2] - 1;
		while (j < g_x && i < g_y)
			if (!ft_check_square(int_arr, i, j, ijemax[2]))
			{
				ijemax[3] = ijemax[2];
				ijemax[2]++;
				ijemax[0] = i;
				ijemax[1] = j;
				i++;
				j++;
			}
			else
				j++;
		i++;
	}
	ft_print_arr(arr, ijemax[0], ijemax[1], ijemax[3]);
}
