/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 14:40:57 by thescriv          #+#    #+#             */
/*   Updated: 2018/10/18 14:40:57 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	char	*tmp;

	tmp = (char *)dest;
	while (len)
	{
		if (*src)
			*tmp++ = *src++;
		else
			*tmp++ = '\0';
		len--;
	}
	return (dest);
}
