/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdupont <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 15:06:05 by tdupont           #+#    #+#             */
/*   Updated: 2016/02/09 16:50:48 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <string.h>
# include "libft.h"

typedef struct	s_map
{
	int			size;
	char		**array;
}				t_map;
typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;
typedef struct	s_etris
{
	char		**pos;
	int			width;
	int			height;
	char		value;
}				t_etris;
t_list			*read_tetri(int fd);
void			print_map(t_map *map);
void			free_map(t_map *map);
t_map			*map_new(int size);
int				place(t_etris *tetri, t_map *map, int x, int y);
void			set_piece(t_etris *tetri, t_map *map, t_point *point, char c);
t_map			*solve(t_list *list);
t_point			*point_new(int x, int y);
t_etris			*tetris_new(char **pos, int width, int height, char c);
void			free_tetris(t_etris *tetri);
t_list			*free_list(t_list *list);
#endif
