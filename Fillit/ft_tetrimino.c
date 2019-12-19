/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetrimino.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 16:42:41 by thescriv          #+#    #+#             */
/*   Updated: 2017/12/20 14:29:47 by tescriva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill.h"

void ft_prep_to_resolve(char **tab, int np, int n)
{
    char *fill;
    int square;
    int x;
	int y;
	int i;

	i = 0;
    y = ft_sqrt((float)(n) * 4.0);
    square = 4;
    x = square + y;
    square = x * x;
    fill = ft_memalloc(square + 1)
    fill[square + 1] = '\0';
	i = 0;
    ft_solve(tab, fill, x, 0);
}

char	*ft_check_tetriminos(char *tab, int lettre)
{
	int i;
	int n;

	n = 0;
	i = 0;
	while (tab[i])
	{
		tab[i] == '#' && (tab[i - 1] == '#' || tab[i + 1] == '#' ||
		 tab[i - 5] == '#' || tab[i + 5] == '#') ? n++ : 0;
		tab[i] == '#' && tab[i - 1] == '#' ? tab[i] = 65 + lettre : 0;
		tab[i] == '#' && tab[i + 1] == '#' ? tab[i] = 65 + lettre : 0;
		tab[i] == '#' && tab[i - 5] == '#' ? tab[i] = 65 + lettre : 0;
		tab[i] == '#' && tab[i + 5] == '#' ? tab[i] = 65 + lettre : 0;
		n == 3 && tab[i] == '#' ? tab[i] = 65 + lettre : 0;
		i++;
	}
	i = 0;
	while (tab[i])
	{
		if (tab[i] == '#')
			ft_error(1);
		i++;
	}
	return (tab);
}

void	ft_tetriminos(char **tab, int np)
{
	int n;
	int lettre;

	lettre = 0;
	n = 0;
	while (n < np + 1)
	{
		tab[n] = ft_check_tetriminos(tab[n], lettre);
		lettre++;
		n++;
	}
	n = 0;
	ft_prep_to_resolve(tab, np, n);
}
