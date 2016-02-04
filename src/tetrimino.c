/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 18:06:28 by pbondoer          #+#    #+#             */
/*   Updated: 2016/02/04 15:04:22 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_etris		tetris_new(char *pos, char width, char height)
{
	t_etris		*tetris;

	tetris = ft_memalloc(sizeof(char) * width * height);
	tetris->pos = pos;
	tetris->w = width;
	tetris->h = height;
	return (tetris);
}
