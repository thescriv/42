/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 14:37:57 by thescriv          #+#    #+#             */
/*   Updated: 2018/10/18 14:37:58 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memchr(const void *str, int c, size_t len)
{
	unsigned char	*tmp;

	tmp = (unsigned char *)str;
	while (len--)
	{
		if (*tmp == (unsigned char)c)
			return (tmp);
		else
			tmp++;
	}
	return (NULL);
}
