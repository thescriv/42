/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 15:23:45 by thescriv          #+#    #+#             */
/*   Updated: 2017/11/25 15:12:10 by tescriva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s1;
	unsigned char	k;

	k = (unsigned char)c;
	s1 = (unsigned char *)s;
	while (n)
	{
		if (*s1 == k)
			return (s1);
		s1++;
		n--;
	}
	return (NULL);
}
