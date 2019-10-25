/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 14:40:23 by thescriv          #+#    #+#             */
/*   Updated: 2018/10/18 14:40:24 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t len)
{
	char	*d;
	char	*s;
	size_t	size;
	size_t	dlen;

	d = (char *)dst;
	s = (char *)src;
	size = (size_t)len;
	while (size-- != 0 && *d != '\0')
		d++;
	dlen = d - dst;
	size = len - dlen;
	if (size == 0)
		return (dlen + ft_strlen(s));
	while (*s != '\0')
	{
		if (size != 1)
		{
			*d++ = *s;
			size--;
		}
		s++;
	}
	*d = '\0';
	return (dlen + s - src);
}
