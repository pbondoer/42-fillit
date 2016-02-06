/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_reader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdupont <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 18:22:59 by tdupont           #+#    #+#             */
/*   Updated: 2016/02/02 20:20:14 by tdupont          ###   ########.fr       */
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
			if ((i + 1) <= 20 && str[i + 1] == '#')
				block++;
			if ((i - 1) >= 0 && str[i - 1] == '#')
				block++;
			if ((i + 5) <= 20 && str[i + 5] == '#')
				block++;
			if ((i - 5) >= 0 && str[i - 5] == '#')
				block++;
			//printf("la Valeur de la Variable Block est %d \n", block);
		}
		i++;
	}
	return (block);
}

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
	if (check_connection(str) != 6 && check_connection(str) != 8)
		return (5);
	return (0);
}

t_list	*read_tetri(int fd)
{
	char	*buf;
	int		count;
	t_list	*list;
	int report;

	report = 0;
	buf = ft_strnew(21);
	list = NULL;
	while ((count = read(fd, buf, 21)) >= 20)
	{
		//printf("%s", buf);
		//printf("Tetrominos Numero %d \n", j);
		if (check_counts(buf, count) != 0)
			report = 1;
		else
			printf("ok valide\n \n");
	}
	if (report == 1)
		ft_putstr("error\n");
	if (count != 0)
		return (NULL);
	return (list);
}

t_vector	*piece_positions(char *str)
{
	int			i;
	int			c;
	t_vector	*pos;

	pos = ft_memalloc(sizeof(t_vector) * 4);
	i = 0;
	c = 0;
	printf("%s", str);
	while (i < 20)
	{
		if (str[i] == '#')
		{
			//printf("c=%d, i=%d, x=%d, y=%d ", c, i, i % 5, i / 5);
			pos[c].x = i % 5;
			pos[c].y = i / 5;
			c++;
		}
		i++;
	}
	return (0);
}
