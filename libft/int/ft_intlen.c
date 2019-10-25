/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tescriva <tescriva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 16:33:43 by tescriva          #+#    #+#             */
/*   Updated: 2019/05/28 11:11:41 by tescriva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_intlen(long nb)
{
	int i;

	i = 0;
	while (nb != 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}
