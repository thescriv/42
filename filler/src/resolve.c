/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 15:37:55 by thescriv          #+#    #+#             */
/*   Updated: 2018/09/24 16:38:49 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

static int		ft_can_fit(t_fill *f, int n, int i)
{
	if (n + f->hepi > f->heigth || i + f->wipi > f->width || n < 0 || i < 0)
		return (0);
	return (1);
}

static int		ft_try_to_place(t_fill *f, int n, int i, int en)
{
	int x;
	int y;
	int compteur;
	int tmpi;

	x = -1;
	compteur = 0;
	tmpi = i;
	while (++x < f->hepi)
	{
		y = -1;
		while (++y < f->wipi)
		{
			if (f->piece[x][y] == '*' && f->bulle[n][i] == en)
				return (0);
			else if (f->piece[x][y] == '*' && f->bulle[n][i] == f->player)
				compteur++;
			i++;
		}
		i = tmpi;
		n++;
	}
	return (compteur == 1 ? 1 : 0);
}

static int		ft_final_place(t_fill *f, int n, int i)
{
	int x;
	int y;
	int score;
	int tmpi;

	x = -1;
	tmpi = i;
	score = 0;
	while (++x < f->hepi)
	{
		y = -1;
		while (++y < f->wipi)
		{
			f->bulle[n][i] > 0 ? score += f->bulle[n][i] : 0;
			i++;
		}
		n++;
		i = tmpi;
	}
	return (score);
}

t_fill			*ft_place(t_fill *f, int n, int i, int en)
{
	if (ft_can_fit(f, n, i) == 1 && ft_try_to_place(f, n, i, en) == 1)
	{
		f->tmpscore = ft_final_place(f, n, i);
		if (f->tmpscore < f->score)
		{
			f->x = n;
			f->y = i;
			f->score = f->tmpscore;
		}
	}
	return (f);
}

t_fill			*ft_resolve(t_fill *f, int en)
{
	int n;
	int i;

	n = 0;
	i = 0;
	while (n < f->heigth)
	{
		while (i < f->width)
		{
			if (f->bulle[n][i] == f->player || f->bulle[n][i] >= 0)
				f = ft_place(f, n, i, en);
			i++;
		}
		i = 0;
		n++;
	}
	return (f);
}
