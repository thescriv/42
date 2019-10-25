/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factoriel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 14:36:22 by thescriv          #+#    #+#             */
/*   Updated: 2018/10/18 14:36:23 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_factoriel(int nb)
{
	int	res;

	res = 1;
	if (nb == 0)
		return (1);
	if (nb < 0 || nb > 12)
		return (0);
	else
	{
		while (nb > 0)
		{
			res = res * nb;
			nb--;
		}
		return (res);
	}
}
