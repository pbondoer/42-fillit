/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 15:19:32 by pbondoer          #+#    #+#             */
/*   Updated: 2016/02/06 23:00:29 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "map.h"
#include "libft.h"
#include "tetrimino.h"

int		solve_map(t_map *map, t_list *list)
{
	size_t		x;
	size_t		y;
	t_etris		*tetri;

	if (list == NULL)
		return (1);
	y = 0;
	tetri = (t_etris *)(list->content);
	while (y < map->size - tetri->height + 1)
	{
		x = 0;
		while (x < map->size - tetri->width + 1)
		{
			if (place(tetri, map, x, y))
			{
				if (solve_map(map, list->next))
					return (1);
				else
					remove_piece(tetri, map, x, y);
			}
			x++;
		}
		y++;
	}
	return (0);
}

t_map	*solve(t_list *list)
{
	t_map	*map;
	size_t	size;

	//TODO: get_minsize
	size = 4;
	map = map_new(size);
	while (!solve_map(map, list))
	{
		size++;
		//TODO: Free old map
		map = map_new(size);
	}
	return (map);
}
