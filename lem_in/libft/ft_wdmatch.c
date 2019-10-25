/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wdmatch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 14:42:27 by thescriv          #+#    #+#             */
/*   Updated: 2018/10/18 14:42:28 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_wdmatch(char *to_find, char *str)
{
	int	i;
	int	j;
	int	stack;

	i = 0;
	j = 0;
	stack = 0;
	while (to_find[i] != '\0' && str[j] != '\0')
	{
		if (to_find[i] == str[j])
		{
			stack++;
			i++;
			j++;
		}
		else
			j++;
	}
	if (stack == ft_strlen(to_find))
		ft_putstr(to_find);
	else
		ft_putchar('\n');
}
