/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_die.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/31 08:16:04 by pbondoer          #+#    #+#             */
/*   Updated: 2016/12/31 08:17:37 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		ft_die(char *reason)
{
	ft_putstr(reason);
	exit(EXIT_FAILURE);
	return (EXIT_FAILURE);
}
