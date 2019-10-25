/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 11:36:48 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/12 19:16:40 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_quit(t_fdf *f)
{
	mlx_destroy_window(f->ptr, f->wnd);
	exit(0);
}

void	ft_clear_int(int **tab, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		ft_memdel((void*)&tab[i]);
		i++;
	}
}

void	ft_assign_rotate(t_fdf *f, int key)
{
	key == 15 ? f->rotate = 1 : 0;
	key == 17 ? f->rotate = 2 : 0;
	key == 16 ? f->rotate = 3 : 0;
	key == 3 ? f->rotate = 4 : 0;
}

void	ft_what_key(t_fdf *f, int key)
{
	key == 11 ? f->color = 0xFFFFFF : 0;
	key == 13 ? f->move++ : 0;
	key == 1 ? f->move-- : 0;
	key == 0 ? f->left += 15 : 0;
	key == 2 ? f->right += 15 : 0;
	key == 8 && f->rgb == 0 ? f->color = 0xFF0000 : 0;
	key == 8 && f->rgb == 1 ? f->color = 0x0000FF : 0;
	key == 8 && f->rgb == 2 ? f->color = 0x008000 : 0;
	key == 8 ? f->rgb++ : 0;
	key == 49 ? f->reset = 1 : 0;
	key == 36 ? f->sp = 1 : 0;
}

int		get_key(int key, void *param)
{
	t_fdf *f;

	f = param;
	if (key == 53)
		ft_quit(f);
	key == 8 && f->rgb == 3 ? f->rgb = 0 : 0;
	ft_clear_int(f->map, f->h);
	free(f->map);
	if (key == 15 || key == 17 || key == 16 || key == 3 || key == 5 || key == 4)
		ft_assign_rotate(f, key);
	if ((key == 18 && f->proj != 1) || (key == 19 && f->proj != 0))
	{
		key == 18 && f->proj != 1 ? f->proj = 1 : 0;
		key == 19 && f->proj != 0 ? f->proj = 0 : 0;
	}
	else if (key == 43 || key == 47)
	{
		key == 43 ? f->sp++ : f->sp--;
		f->sp == 0 ? f->sp = 1 : 0;
	}
	ft_what_key(f, key);
	mlx_destroy_image(f->ptr, f->i.jpg);
	ft_ready_draw(f);
	return (0);
}
