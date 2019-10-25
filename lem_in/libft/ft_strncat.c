/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 14:40:45 by thescriv          #+#    #+#             */
/*   Updated: 2018/10/18 14:40:45 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t len)
{
	char	*tmp;

	tmp = (char *)dest;
	while (*tmp != '\0')
		tmp++;
	while (len-- > 0 && *src != '\0')
		*tmp++ = *src++;
	*tmp = '\0';
	return (dest);
}
