/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroelle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 11:49:56 by jroelle           #+#    #+#             */
/*   Updated: 2018/11/05 14:27:43 by jroelle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

t_list	*ft_ret(int fd)
{
	int		ret;
	char	*str;
	char	buf[BUF_SIZE + 1];
	t_list	*list;

	list = NULL;
	while ((ret = read(fd, buf, BUF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		str = (char *)malloc(sizeof(char) * (ret + 1));
		ft_strcpy(str, buf);
		ft_list_push_back(&list, str);
	}
	return (list);
}
