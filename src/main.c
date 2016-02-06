/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 17:41:37 by pbondoer          #+#    #+#             */
/*   Updated: 2016/02/06 16:30:56 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <fcntl.h>
#include "fillit.h"
#include "tetrimino.h"

int		main(int argc, char **argv)
{
	t_list	*list;

	if (argc != 2)
	{
		ft_putstr("error");
		return (0);
	}
	printf("read %s\n", argv[1]);

	if ((list = read_tetri(open(argv[1], O_RDONLY))) == NULL)
	{
		ft_putstr("error: got null\n");
		return (0);
	}

	int x;
	int y;
	while (list)
	{
		x = 0;
		y = 0;
		printf("[main] w=%d, h=%d\n", ((t_etris *)list->content)->width, ((t_etris *)list->content)->height);
		while (y < ((t_etris *)list->content)->height)
		{
			printf("%s\n", ((t_etris *)list->content)->pos[y]);
			y++;
		}
		printf("===\n");
		list = list->next;
	}
}
