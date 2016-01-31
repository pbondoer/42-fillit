/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 15:45:52 by pbondoer          #+#    #+#             */
/*   Updated: 2016/01/31 23:31:52 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	place(t_map *map, t_etris *mino, t_vector *pos, char id)
{
	int			i;
	t_vector	cur_pos;

	if (pos->x + mino->size->x > map->size->x
			|| pos->y + mino->size->y > map->size->y)
		return (-1);
	i = 0;
	while (i < 4)
	{
		cur_pos = get_pos(mino, i);
		if (!map->array[pos->x + cur_pos->x][pos->y + cur_pos->y])
		{
			while (i > 0)
			{
				i--;
				remove(map, mino, pos);
			}
			return (0);
		}
		map->array[pos->x + cur_pos->x][pos->y + cur_pos->y] = id;
		i++;
	}
	return (1);
}

/*
** remove() assumes you have already added mino; no checks are performaed.
*/

int	remove(t_map *map, t_etris *mino, t_vector *pos)
{
	int			i;
	t_vector	cur_pos;

	i = 0;
	while (i < 4)
	{
		cur_pos = get_pos(mino, i);
		map->array[pos->x + cur_pos->x][pos->y + cur_pos->y] = 0;
	}
	return (1);
}
