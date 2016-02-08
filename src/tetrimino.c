/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 18:06:28 by pbondoer          #+#    #+#             */
/*   Updated: 2016/02/08 11:20:02 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void		free_tetris(t_etris *tetri)
{
	size_t y;

	y = 0;
	while (y < tetri->height)
	{
		ft_memdel((void **)(&(tetri->pos[y])));
		y++;
	}
	ft_memdel((void **)(&(tetri->pos)));
	ft_memdel((void **)&tetri);
	}

t_etris		*tetris_new(char **pos, size_t width, size_t height, char value)
{
	t_etris		*tetris;

	tetris = ft_memalloc(sizeof(t_etris));
	tetris->pos = pos;
	tetris->width = width;
	tetris->height = height;
	tetris->value = value;
	return (tetris);
}

t_point		*point_new(size_t x, size_t y)
{
	t_point		*point;

	point = ft_memalloc(sizeof(t_point));
	point->x = x;
	point->y = y;
	return (point);
}
