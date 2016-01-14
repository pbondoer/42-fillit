/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 13:43:48 by pbondoer          #+#    #+#             */
/*   Updated: 2016/01/14 16:16:47 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetrimino.h"
#include <stdio.h>
#include <stdlib.h>

/*
** Tetrimino data is stored on 2 bits
** One position is 4 bits (x and y)
** 4 bits * 4 positions = 16 bits = 2 chars * 8 bits
** Obtain position by using the chars and bitshifting/masking
*/

t_vector	*get_pos(t_etris *mino, char index)
{
	t_vector *v;

	v = ft_memalloc(sizeof(t_vector));
	v->x = ((mino->x >> pos * 2) & 3);
	v->y = ((mino->y >> pos * 2) & 3);
	return (v);
}

t_vector	*set_pos(t_etris *mino, char index, t_vector *pos)
{
	mino->x = (mino->x & ~(3 << index * 2)) | pos->x << index * 2;
	mino->y = (mino->y & ~(3 << index * 2)) | pos->y << index * 2;
	return (pos);
}

t_vector	*get_size(t_etris *mino)
{
	t_vector *v;

	v = ft_memalloc(sizeof(t_vector));
	v->x = ((mino->size >> 0) & 3);
	v->y = ((mino->size >> 2) & 3);
	return (v);
}

t_vector	*set_size(t_etris *mino, t_vector *size)
{
	mino->size = (size->x) | (size->y >> 2);
}
