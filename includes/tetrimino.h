/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 17:58:37 by pbondoer          #+#    #+#             */
/*   Updated: 2016/01/27 18:11:58 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRIMINO_H
# define TETRIMINO_H

typedef struct	s_vector
{
	char		x;
	char		y;
}				t_vector;
typedef struct	s_etris
{
	t_vector	*pos;
	t_vector	size;
}				t_etris;
#endif
