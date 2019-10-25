/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:44:51 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/12 19:35:53 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int		ft_find_c(char *s, char c)
{
	int i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

void	ft_get_value(t_fdf *f)
{
	f->j = 1;
	f->proj == 0 ? f->y = 0 : 0;
	f->proj == 1 ? f->y = 25 : 0;
	f->proj == 1 ? f->x = 25 : 0;
}

int		ft_get_dot(t_fdf *f, int nb)
{
	int dot;
	int k;

	k = 0;
	f->z = nb + f->move;
	f->rotate == 1 ? f->x += 0.174533 : 0;
	f->rotate == 2 ? f->x -= 0.174533 : 0;
	f->rotate == 3 ? f->y += 0.174533 : 0;
	f->rotate == 4 ? f->y -= 0.174533 : 0;
	dot = ((f->x - f->z) * WIDTH + f->y) * f->sp;
	if (dot > 0)
	{
		f->right > 0 ? dot += f->right : 0;
		f->left > 0 ? dot -= f->left : 0;
		k = 1;
	}
	f->y++;
	f->proj == 1 ? f->x++ : 0;
	return (k == 1 ? dot : -1);
}

void	ft_proj_para(t_fdf *f)
{
	int i;
	int n;

	n = -1;
	f->x = 1;
	while (f->tab[++n] != NULL)
	{
		i = 0;
		if (!(f->map[n] = (int*)malloc(sizeof(int) * f->w)))
			exit(0);
		ft_get_value(f);
		while (f->tab[n][i])
		{
			if (ft_isdigit(f->tab[n][i]) == 1 || f->tab[n][i] == '-')
			{
				f->map[n][f->j++] = ft_get_dot(f, ft_atoi(f->tab[n] + i));
				i += ft_find_c(f->tab[n] + i, ' ');
			}
			else
				i++;
		}
		f->map[n][0] = f->j;
		f->x++;
	}
}

void	ft_proj_iso(t_fdf *f)
{
	int i;
	int n;

	n = -1;
	while (f->tab[++n] != NULL)
	{
		i = 0;
		if (!(f->map[n] = (int*)malloc(sizeof(int) * f->w)))
			exit(0);
		ft_get_value(f);
		f->proj == 1 ? f->y -= n : 0;
		f->proj == 1 ? f->x -= f->y : 0;
		while (f->tab[n][i])
		{
			if (ft_isdigit(f->tab[n][i]) == 1 || f->tab[n][i] == '-')
			{
				f->map[n][f->j++] = ft_get_dot(f, ft_atoi(f->tab[n] + i));
				i += ft_find_c(f->tab[n] + i, ' ');
			}
			else
				i++;
		}
		f->map[n][0] = f->j;
	}
}
