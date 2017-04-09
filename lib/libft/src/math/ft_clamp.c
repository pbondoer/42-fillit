/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clamp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 23:19:12 by pbondoer          #+#    #+#             */
/*   Updated: 2016/12/27 23:20:27 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Clamps a value between two values
*/

double		ft_clamp(double i, double a, double b)
{
	if (i < a)
		i = a;
	if (i > b)
		i = b;
	return (i);
}
