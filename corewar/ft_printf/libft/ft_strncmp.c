/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 19:15:52 by vduong            #+#    #+#             */
/*   Updated: 2018/12/06 12:52:45 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] == s2[i] && i < (n - 1)))
	{
		if (s1[i] == 0 || s2[i] == 0)
			return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
		i++;
	}
	return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
}
