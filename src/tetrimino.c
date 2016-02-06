/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 18:06:28 by pbondoer          #+#    #+#             */
/*   Updated: 2016/02/06 20:42:38 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetrimino.h"
#include "libft.h"

t_etris		*tetris_new(char **pos, char width, char height, char value)
{
	t_etris		*tetris;
	int			y;

	tetris = ft_memalloc(sizeof(t_etris));
	tetris->pos = ft_memalloc(sizeof(char *) * height);
	y = 0;
	while (y < height)
	{
		tetris->pos[y] = ft_strdup(pos[y]);
		y++;
	}
	tetris->width = width;
	tetris->height = height;
	tetris->value = value;
	return (tetris);
}

t_point		*point_new(char x, char y)
{
	t_point		*point;

	point = ft_memalloc(sizeof(t_point));
	point->x = x;
	point->y = y;
	return (point);
}
