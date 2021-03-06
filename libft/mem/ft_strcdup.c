/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tescriva <tescriva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 11:15:17 by tescriva          #+#    #+#             */
/*   Updated: 2019/05/28 11:13:00 by tescriva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcdup(const char *s1, int c)
{
	int i;

	i = 0;
	while (s1[i] != c)
		i++;
	return (ft_strndup(s1, i));
}
