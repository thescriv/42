/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 10:52:14 by vduong            #+#    #+#             */
/*   Updated: 2018/12/07 10:52:43 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int	invalid_int(char *s)
{
	int	len;

	if (*s == '+')
		s++;
	len = ft_strlen(s);
	if (*s != '-' ?
	len > 10 || (len == 10 && ft_strncmp(s, "2147483647", 10) > 0) :
	len > 11 || (len == 11 && ft_strncmp(s, "-2147483648", 11) > 0))
		return (1);
	if (*s == '-')
		s++;
	while (*s)
	{
		if (!(ft_isdigit(*s)))
			return (1);
		s++;
	}
	return (0);
}
