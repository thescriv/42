/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tescriva <tescriva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 13:18:48 by tescriva          #+#    #+#             */
/*   Updated: 2018/05/16 13:06:46 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*dest;
	int		i;

	i = ft_strlen(s1);
	dest = (char*)malloc(sizeof(char) * i + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (s1[i] || n != 0)
	{
		dest[i] = s1[i];
		i++;
		n--;
	}
	dest[i] = '\0';
	return (dest);
}
