/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lerpi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 00:34:09 by pbondoer          #+#    #+#             */
/*   Updated: 2016/12/28 01:09:05 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_lerpi(int first, int second, double p)
{
	if (first == second)
		return (first);
	if (p == 0.0f)
		return (first);
	if (p == 1.0f)
		return (second);
	return ((int)((double)first + (second - first) * p));
}
