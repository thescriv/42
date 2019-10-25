/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tescriva <tescriva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 19:32:39 by tescriva          #+#    #+#             */
/*   Updated: 2017/11/26 16:28:33 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char		*s;
	int			i;
	long		j;

	if (n == 0 || !n)
	{
		s = (char*)malloc(sizeof(char) * 2);
		s[0] = '0';
		s[1] = '\0';
		return (s);
	}
	j = (long)n;
	n < 0 ? j *= -1 : 0;
	i = ft_intlen(j);
	s = (char*)malloc(sizeof(*s) * (n < 0 ? ++i : i));
	if (!s)
		return (NULL);
	s[i] = '\0';
	n < 0 ? s[0] = '-' : 0;
	while (j != 0)
	{
		s[--i] = (j % 10) + '0';
		j /= 10;
	}
	return (s);
}
