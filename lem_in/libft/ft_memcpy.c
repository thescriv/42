/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 14:38:05 by thescriv          #+#    #+#             */
/*   Updated: 2018/10/18 14:38:05 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*tmp;
	const char	*cpy;

	tmp = (char*)dest;
	cpy = (const char*)src;
	while (n--)
	{
		*tmp = *cpy;
		tmp++;
		cpy++;
	}
	return (dest);
}
