/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 14:14:12 by pbondoer          #+#    #+#             */
/*   Updated: 2016/01/14 16:55:19 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRIMINO_H
# define TETRIMINO_H

/*
** For information on how tetrimino data is handled, please refer
** to tetrimino.c
*/

typedef struct		s_etris
{
	unsigned char	x;
	unsigned char	y;
	unsigned char	size;
}					t_etris;

/*
** Vectors store size information (albeit inefficiently)
*/
typedef struct		s_vector
{
	char			x;
	char			y;
}					t_vector;
#endif
