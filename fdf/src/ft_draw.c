/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:57:08 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/14 18:22:02 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_draw_line(t_fdf *f, int x2, int y2)
{
	int i;
	int xinc;
	int yinc;

	f->dx = abs(x2 - f->x1);
	f->dy = abs(y2 - f->y1);
	i = 0;
	xinc = f->x1 < x2 ? 1 : -1;
	yinc = f->y1 < y2 ? 1 : -1;
	f->e = f->dy > f->dx ? f->dy / 2 : f->dx / 2;
	while (i++ < (f->dy > f->dx ? f->dy : f->dx))
	{
		f->x >= 0 && f->y >= 0 && f->x < HEIGTH && f->y < WIDTH ?
		f->i.data[f->x * WIDTH + f->y] = f->color : 0;
		f->dy > f->dx ? f->y += yinc : (f->x += xinc);
		f->e += f->dy > f->dx ? f->dx : f->dy;
		if (f->e > (f->dy > f->dx ? f->dy : f->dx))
		{
			f->e -= f->dy > f->dx ? f->dy : f->dx;
			f->dy > f->dx ? f->x += xinc : (f->y += yinc);
		}
	}
}

void	ft_draw(t_fdf *f)
{
	int n;
	int i;

	n = -1;
	while (++n < f->h)
	{
		i = 0;
		while (++i < f->map[n][0])
		{
			if ((f->x1 = f->map[n][i] / WIDTH) >= 0
			&& (f->y1 = f->map[n][i] % WIDTH) >= 0)
			{
				f->x = f->x1;
				f->y = f->y1;
				if (i + 1 < f->map[n][0])
					ft_draw_line(f, f->map[n][i + 1] / WIDTH,
						f->map[n][i + 1] % WIDTH);
				f->x = f->x1;
				f->y = f->y1;
				if (n + 1 < f->h && i < f->map[n + 1][0])
					ft_draw_line(f, f->map[n + 1][i] / WIDTH,
						f->map[n + 1][i] % WIDTH);
			}
		}
	}
}

void	ft_ready_draw(t_fdf *f)
{
	if (f->reset == 1)
	{
		f->sp = (WIDTH / f->w - 1) * 1.1;
		f->sp == 0 ? f->sp = 1 : 0;
		f->right = 0;
		f->left = 0;
		f->move = 0;
		f->reset = 0;
		f->rotate = 0;
		f->color = 0xFFFFFF;
	}
	f->i.jpg = mlx_new_image(f->ptr, WIDTH, HEIGTH);
	f->i.data = (int*)mlx_get_data_addr(f->i.jpg, &f->i.bpp, &f->i.len, &f->e);
	f->map = (int**)malloc(sizeof(int*) * f->h);
	f->proj == 0 ? ft_proj_para(f) : ft_proj_iso(f);
	ft_draw(f);
	mlx_put_image_to_window(f->ptr, f->wnd, f->i.jpg, 0, 0);
	mlx_key_hook(f->wnd, get_key, f);
	mlx_loop(f->ptr);
}
