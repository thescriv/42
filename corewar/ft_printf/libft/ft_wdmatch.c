/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wdmatch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 15:31:00 by vduong            #+#    #+#             */
/*   Updated: 2018/12/06 12:53:55 by vduong           ###   ########.fr       */
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
