/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 12:08:57 by thescriv          #+#    #+#             */
/*   Updated: 2018/09/24 15:04:58 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int i;
	int neg;
	int nb;

	neg = 0;
	i = 0;
	if (!str)
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	str[i] == '-' ? neg++ : 0;
	str[i] == '-' || str[i] == '+' ? i++ : 0;
	nb = 0;
	while (str[i] && str[i] <= '9' && str[i] >= '0')
	{
		nb = nb * 10;
		nb = nb + (str[i] - 48);
		i++;
	}
	return (neg == 1 ? (-nb) : (nb));
}
