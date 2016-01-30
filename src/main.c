/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 17:41:37 by pbondoer          #+#    #+#             */
/*   Updated: 2016/01/30 17:45:46 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <fcntl.h>
#include "fillit.h"

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("error");
		return (0);
	}
	printf("read %s\n", argv[1]);
	if (read_tetri(open(argv[1], O_RDONLY)) == NULL)
	{
		ft_putstr("error\n");
	}
}
