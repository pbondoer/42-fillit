/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 17:58:37 by pbondoer          #+#    #+#             */
/*   Updated: 2016/02/06 21:44:30 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRIMINO_H
# define TETRIMINO_H
# include <string.h>

typedef struct	s_point
{
	size_t		x;
	size_t		y;
}				t_point;

typedef struct	s_etris
{
	char		**pos;
	size_t		width;
	size_t		height;
	char		value;
}				t_etris;
t_point		*point_new(char x, char y);
t_etris		*tetris_new(char **pos, char width, char height, char value);
#endif
