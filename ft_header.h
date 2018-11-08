/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroelle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 11:45:26 by jroelle           #+#    #+#             */
/*   Updated: 2018/11/07 19:41:23 by mnarbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEADER_H
# define FT_HEADER_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define BUF_SIZE 1024

int		g_x;
int		g_y;
char	g_full;
char	g_obs;
char	g_empty;

typedef struct		s_list
{
	struct s_list	*next;
	char			*data;
}					t_list;

t_list				*ft_ret(int fd);
char				*ft_strcat(char *dest, char *src);
int					ft_strlen(char *str);
t_list				*ft_create_elem(char *data);
void				ft_list_push_back(t_list **begin_list, char *data);
char				*ft_strcpy(char *dest, char *src);
int					ft_atoi(char *str, t_list **list);
char				**ft_create_arr(t_list *list);
int					ft_int_arr(char **arr);
void				ft_make_map(int **int_arr, char **arr);
int					ft_ycmp(int y_atoi, t_list *list);
int					check_ind(t_list *list);
void				ft_putstr_err(void);
void				ft_list_clear(t_list **begin_list);
int					ft_init_symbol(t_list **list);
void				ft_xcmp(int *ind, int *x, t_list **list);

#endif
