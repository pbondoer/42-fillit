/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 17:43:27 by pbondoer          #+#    #+#             */
/*   Updated: 2016/01/26 15:11:14 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int		check(char **str)
{

	return (1);
}

/*
** Read tetriminos from fd and put them in a list.
**
** We use 21 sized reads to read piece by piece since there are
** 4 lines made of 4 chars (+ newline) = 20 chars + sep. newline = 21 chars
*/

t_list	*read(int fd)
{
	char	*buf;
	int		count;
	t_list	*list;

	buf = ft_memalloc(sizeof(char) * 21);
	t_list = NULL;
	while ((count = read(fd, buf, 21)) >= 20)
	{
		
	}
	if (count != 0)
	{
		//TODO: Cleanup
		return (NULL);
	}
	return (list);
}
