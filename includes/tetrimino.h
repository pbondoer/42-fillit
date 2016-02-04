/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 17:58:37 by pbondoer          #+#    #+#             */
/*   Updated: 2016/02/04 18:17:27 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRIMINO_H
# define TETRIMINO_H
typedef struct	s_point
{
	char		x;
	char		y;
}				t_point;

typedef struct	s_etris
{
	char		**pos;
	char		width;
	char		height;
}				t_etris;
t_point		*point_new(char x, char y);
t_etris		*tetris_new(char **pos, char width, char height);
#endif
