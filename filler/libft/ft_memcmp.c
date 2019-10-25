/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 15:12:17 by thescriv          #+#    #+#             */
/*   Updated: 2017/11/18 16:50:45 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				i;
	unsigned char	*sa;
	unsigned char	*sb;

	sa = (unsigned char *)s1;
	sb = (unsigned char *)s2;
	i = 0;
	while (n)
	{
		if (sa[i] != sb[i])
			return (sa[i] - sb[i]);
		i++;
		n--;
	}
	return (0);
}
