/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 18:59:01 by pbondoer          #+#    #+#             */
/*   Updated: 2016/02/06 19:01:23 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstat(t_list lst, size_t val)
{
	int i;

	i = 0;
	while (i < val && lst != null)
	{
		lst = lst->next;
		i++;
	}
	return (lst);
}
