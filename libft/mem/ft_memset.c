/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 13:54:47 by thescriv          #+#    #+#             */
/*   Updated: 2019/05/28 11:12:58 by tescriva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	unsigned char	k;
	int				i;

	k = (unsigned char)c;
	str = (unsigned char *)b;
	i = 0;
	while (len--)
		str[i++] = k;
	return (str);
}
