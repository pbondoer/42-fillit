/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 17:41:37 by pbondoer          #+#    #+#             */
/*   Updated: 2016/02/06 23:02:11 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <fcntl.h>
#include "fillit.h"
#include "tetrimino.h"
#include "map.h"

int		main(int argc, char **argv)
{
	t_list	*list;

	if (argc != 2)
	{
		ft_putstr("error");
		return (0);
	}

	if ((list = read_tetri(open(argv[1], O_RDONLY))) == NULL)
	{
		ft_putstr("error: got null\n");
		return (0);
	}

	t_map	*map;
	
	map = solve(list);
	size_t i;

	i = 0;
	while (i < map->size)
	{
		printf("%s\n", map->array[i]);
		i++;
	}
}
