/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 14:39:00 by thescriv          #+#    #+#             */
/*   Updated: 2018/10/18 14:39:01 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	if (nb <= 0)
		return (0);
	else
	{
		while (i <= nb)
		{
			if (i == nb)
				return (j);
			else
			{
				i = i + (2 * j + 1);
				j++;
			}
		}
		return (0);
	}
}
