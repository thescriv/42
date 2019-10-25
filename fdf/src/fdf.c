/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tescriva <tescriva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 19:23:24 by tescriva          #+#    #+#             */
/*   Updated: 2018/11/12 19:18:52 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int		ft_check(t_fdf *f)
{
	int i;
	int n;

	n = -1;
	while (f->tab[++n])
	{
		i = 0;
		while (f->tab[n][i])
		{
			if ((f->tab[n][i] >= '0' && f->tab[n][i] <= '9')
			|| f->tab[n][i] == ' ' || f->tab[n][i] == '-')
			{
				if (f->tab[n][i] == '-' && f->tab[n][i + 1] == '-')
					return (0);
				i++;
			}
			else
				return (0);
		}
		f->w < i ? f->w = i : 0;
	}
	f->h = n;
	return (1);
}

void	ft_start(t_fdf *f, int fd)
{
	char *tmp;

	tmp = ft_read_data(fd);
	f->tab = ft_strsplit(tmp, '\n');
	ft_strdel(&tmp);
	if (ft_check(f) == 1)
	{
		f->reset = 1;
		f->proj = 1;
		f->rotate = 0;
		f->ptr = mlx_init();
		f->wnd = mlx_new_window(f->ptr, WIDTH, HEIGTH, "fdf");
		ft_ready_draw(f);
	}
}

int		main(int ac, char **av)
{
	t_fdf	f;
	int		fd;

	fd = 0;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY, O_NOFOLLOW);
		if (fd == -1)
			return (0);
		ft_start(&f, fd);
		close(fd);
	}
	return (0);
}
