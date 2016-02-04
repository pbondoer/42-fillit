/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 17:43:27 by pbondoer          #+#    #+#             */
/*   Updated: 2016/02/04 18:45:19 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "tetrimino.h"
#include <stdio.h>

void	min_max(char *str, t_point *min, t_point *max)
{
	int i;

	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if (i / 5 < min->y)
				min->y = i / 5;
			if (i / 5 > max->y)
				max->y = i / 5;
			if (i % 5 < min->x)
				min->x = i % 5;
			if (i % 5 > max->x)
				max->x = i % 5;
		}
		i++;
	}
}

t_etris	*get_piece(char *str)
{
	t_point		*min;
	t_point		*max;
	char		**pos;
	int			i;
	t_etris		*tetri;

	min = point_new(3, 3);
	max = point_new(0, 0);
	min_max(str, min, max);
	pos = ft_memalloc(sizeof(char *) * (max->y - min->y + 1));
	i = 0;
	while (i < max->y - min->y + 1)
	{
		pos[i] = ft_strnew(max->x - min->x + 1);
		printf("x = %d, w = %d, y = %d\n", min->x, max->x - min->x + 1, i);
		ft_strncpy(pos[i], str + (min->x) + (i + min->y) * 5, max->x - min->x + 1);
		i++;
	}
	tetri = tetris_new(pos, max->x - min->x + 1, max->y - min->y + 1);
	ft_memdel((void **)&min);
	ft_memdel((void **)&max);
	return (tetri);
}

/*
 * Checks connection counts, if we have 6 or 8 connections, the tetrimino is
 * valid. Otherwise, our tetrimino is not contiguous.
 */

int		check_connection(char *str)
{
	int block;
	int i;
	
	block = 0; 
	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if ((i + 1) < 20 && str[i + 1] == '#')
				block++;
			if ((i - 1) >= 0 && str[i - 1] == '#')
				block++;	
			if ((i + 5) < 20 && str[i + 5] == '#')
				block++;	
			if ((i - 5) >= 0 && str[i - 5] == '#')
				block++;
		}
		i++;
	}
	return (block == 6 || block == 8);
}

/*
 ** Checks character counts and that chunk format is valid.
 */

int		check_counts(char *str, int count)
{
	int i;
	int blocs;

	blocs = 0;
	i = 0;
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (!(str[i] == '#' || str[i] == '.'))
				return (1);
			if (str[i] == '#' && blocs++ > 4)
				return (2);
		}
		else if (str[i] != '\n')
			return (3);
		i++;
	}
	if (count == 21 && str[20] != '\n')
		return (4);
	if (!check_connection(str))
		return (5);
	return (0);
}

/*
 ** Read tetriminos from fd and put them in a list.
 **
 ** We use 21 sized reads to read piece by piece since there are
 ** 4 lines made of 4 chars (+ newline) = 20 chars + sep. newline = 21 chars
 */

t_list	*read_tetri(int fd)
{
	char	*buf;
	int		count;
	t_list	*list;
	t_etris	*tetris;

	buf = ft_strnew(21);
	list = NULL;
	tetris = NULL;
	while ((count = read(fd, buf, 21)) >= 20)
	{
		if (check_counts(buf, count) != 0 || (tetris = get_piece(buf)) == NULL)
		{
			//TODO: Cleanup
			printf("cleanup read_tetri\n");
			return (NULL);
		}
		printf("adding tetris: w=%d, h=%d\n", tetris->width, tetris->height);
		ft_lstadd(&list, ft_lstnew(tetris, sizeof(t_etris)));
	}
	if (count != 0)
		return (NULL);
	return (list);
}
