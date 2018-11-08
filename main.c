/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroelle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 13:12:44 by jroelle           #+#    #+#             */
/*   Updated: 2018/11/07 22:23:25 by jroelle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

void	ft_start(int fd)
{
	char	**arr;
	t_list	*begin_list;

	arr = NULL;
	begin_list = ft_ret(fd);
	if (!begin_list || !(arr = ft_create_arr(begin_list))
			|| !(ft_int_arr(arr)))
		ft_putstr_err();
	if (fd)
		close(fd);
	ft_list_clear(&begin_list);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		i;

	if (argc < 2)
		ft_start(0);
	else
	{
		i = 1;
		while (i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			ft_start(fd);
			if (i != argc - 1)
				write(1, "\n", 1);
			i++;
		}
	}
	return (0);
}
