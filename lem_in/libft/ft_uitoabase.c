/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoabase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 14:42:21 by thescriv          #+#    #+#             */
/*   Updated: 2018/10/18 14:42:21 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_count_char_len(unsigned int value, int base)
{
	int	len;

	len = -1;
	if (value == 0)
		return (0);
	while (value != 0)
	{
		value = value / base;
		len++;
	}
	return (len);
}

char		*ft_uitoabase(unsigned int value, int base)
{
	char	*tab;
	char	*dest;
	int		i;

	dest = NULL;
	tab = NULL;
	if (base == 10)
		return (ft_itoa(value));
	if (base < 2 && base > 16)
		return (NULL);
	if ((tab = (char *)malloc(sizeof(char) * 17)))
		ft_strcpy(tab, "0123456789abcdef");
	i = ft_count_char_len(value, base);
	if (!(dest = (char *)malloc(sizeof(char) * (i + 2))))
		return (NULL);
	dest[i + 1] = 0;
	while (i >= 0)
	{
		dest[i--] = tab[value % base];
		value = value / base;
	}
	free(tab);
	return (dest);
}
