/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 12:50:16 by thescriv          #+#    #+#             */
/*   Updated: 2018/09/24 16:48:29 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

static t_fill		*ft_value_2(t_fill *f, int n, int i, int val)
{
	if (i - 1 >= 0 && f->bulle[n][i - 1] == val)
		f->bulle[n][i] = 1;
	if (n - 1 >= 0 && f->bulle[n - 1][i] == val)
		f->bulle[n][i] = 1;
	if (i + 1 < f->width && f->bulle[n][i + 1] == val)
		f->bulle[n][i] = 1;
	if (n + 1 < f->heigth && f->bulle[n + 1][i] == val)
		f->bulle[n][i] = 1;
	if (n + 1 < f->heigth && i - 1 >= 0 && f->bulle[n + 1][i - 1] == val)
		f->bulle[n][i] = 1;
	if (n + 1 < f->heigth && i + 1 < f->width && f->bulle[n + 1][i + 1] == val)
		f->bulle[n][i] = 1;
	if (n - 1 >= 0 && i + 1 < f->width && f->bulle[n - 1][i + 1] == val)
		f->bulle[n][i] = 1;
	if (n - 1 >= 0 && i - 1 >= 0 && f->bulle[n - 1][i - 1] == val)
		f->bulle[n][i] = 1;
	return (f);
}

static t_fill		*ft_value(t_fill *f, int n, int i, int val)
{
	if (i - 1 >= 0 && f->bulle[n][i - 1] == val)
		f->bulle[n][i] = val + 1;
	if (n - 1 >= 0 && f->bulle[n - 1][i] == val)
		f->bulle[n][i] = val + 1;
	if (i + 1 < f->width && f->bulle[n][i + 1] == val)
		f->bulle[n][i] = val + 1;
	if (n + 1 < f->heigth && f->bulle[n + 1][i] == val)
		f->bulle[n][i] = val + 1;
	if (n + 1 < f->heigth && i - 1 >= 0 && f->bulle[n + 1][i - 1] == val)
		f->bulle[n][i] = val + 1;
	if (n + 1 < f->heigth && i + 1 < f->width && f->bulle[n + 1][i + 1] == val)
		f->bulle[n][i] = val + 1;
	if (n - 1 >= 0 && i + 1 < f->width && f->bulle[n - 1][i + 1] == val)
		f->bulle[n][i] = val + 1;
	if (n - 1 >= 0 && i - 1 >= 0 && f->bulle[n - 1][i - 1] == val)
		f->bulle[n][i] = val + 1;
	return (f);
}

static t_fill		*ft_put_1(t_fill *f, int en)
{
	int i;
	int n;

	n = 0;
	i = 0;
	while (n < f->heigth)
	{
		while (i < f->width)
		{
			if (f->bulle[n][i] == 0)
				f = ft_value_2(f, n, i, en);
			i++;
		}
		i = 0;
		n++;
	}
	return (f);
}

t_fill				*ft_setup_resolve(t_fill *f, int en)
{
	int i;
	int n;
	int value;

	f = ft_put_1(f, en);
	value = 1;
	while (value < f->width)
	{
		n = 0;
		i = 0;
		while (n < f->heigth)
		{
			while (i < f->width)
			{
				if (f->bulle[n][i] == 0)
					f = ft_value(f, n, i, value);
				i++;
			}
			i = 0;
			n++;
		}
		value++;
	}
	return (f);
}
