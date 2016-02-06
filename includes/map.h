/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 15:46:03 by pbondoer          #+#    #+#             */
/*   Updated: 2016/02/06 21:15:48 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include <string.h>
# include "tetrimino.h"
# include "libft.h"

typedef struct		s_map
{
	size_t		size;
	char		**array;
}					t_map;
t_map	*map_new(size_t size);
int		place(t_etris *tetri, t_map *map, size_t x, size_t y);
void	remove_piece(t_etris *tetri, t_map *map, size_t x, size_t y);
t_map	*solve(t_list *list);
#endif
