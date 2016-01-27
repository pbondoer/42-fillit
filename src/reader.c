/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 17:43:27 by pbondoer          #+#    #+#             */
/*   Updated: 2016/01/27 20:50:32 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

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
	while ((count = read(fd, buf, 21)) >= 20)
	{
		if (check_counts(buf, count))
			return (NULL);
		if (build_piece(buf, tetris))
			return (NULL);
		ft_lstadd(&list, ft_lstnew(tetris, sizeof(tetris)));
	}
	if (count != 0)
		return (NULL);
	return (list);
}
