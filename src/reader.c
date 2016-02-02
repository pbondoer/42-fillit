/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 17:43:27 by pbondoer          #+#    #+#             */
/*   Updated: 2016/02/02 15:48:58 by tdupont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "tetrimino.h"
#include <stdio.h>
int check_connection(char *str)
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
			if ((i - 1) > 0 && str[i - 1] == '#')
				block++;	
			if ((i + 1) < 20 && str[i + 5] == '#')
				block++;	
			if ((i - 1) > 0 && str[i - 5] == '#')
				block++;
			printf("la Valeur de la Variable Block est %d \n", block);
		}
		i++;
	}
	return (block);
}

t_vector	*piece_positions(char *str)
{
	int			i;
	int			c;
	t_vector	*pos;

	//printf("piece_positions\n");
	pos = ft_memalloc(sizeof(t_vector) * 4);
	i = 0;
	c = 0;
	printf("%s", str);
	//while (i < 20)
	//{
	//if (str[i] == '#')
	//{
	//printf("c=%d, i=%d, x=%d, y=%d ", c, i, i % 5, i / 5);
	pos[c].x = i % 5;
	pos[c].y = i / 5;
	check_connection(str);
	//c++;
	//}
	//i++;
	//}
	return (0);
}

t_etris		*build_piece(char *str)
{
	int			i;
	t_vector	*pos;
	//	t_etris		*piece;

	//printf("build_piece\n");
	pos = piece_positions(str);
	i = 0;
	while (i < 4)
	{
		i++;
	}
	return (NULL);
}


/*
 ** Checks character counts and that chunk format is valid.
 */

int		check_counts(char *str, int count)
{
	int i;
	int blocs;

	//printf("check_counts\n");
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

	//printf("read_tetri\n");
	buf = ft_strnew(21);
	list = NULL;
	while ((count = read(fd, buf, 21)) >= 20)
	{
		//printf("%s", buf);
		if (check_counts(buf, count) != 0)
			printf("error");
		//return (NULL);
		if ((tetris = build_piece(buf)) != NULL)
			return (NULL);
		//printf("piece ok, adding\n\n");
		ft_lstadd(&list, ft_lstnew(tetris, sizeof(tetris)));
	}
	if (count != 0)
		return (NULL);
	return (list);
}
