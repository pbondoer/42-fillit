/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 18:06:28 by pbondoer          #+#    #+#             */
/*   Updated: 2016/01/27 18:17:30 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_etris		tetris_new(t_vector pos, t_vector size)
{
	t_etris		*tetris;

	tetris = ft_memalloc(sizeof(t_etris));
	tetris->pos = pos;
	tetris->size = size;
	return (tetris);
}

t_vector	*vector_new(char x, char y)
{
	t_vector	*vector;

	vector = ft_memalloc(sizeof(t_vector));
	vector->x = x;
	vector->y = y;
	return (vector);
}
