/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 11:02:16 by thescriv          #+#    #+#             */
/*   Updated: 2018/09/24 18:18:10 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

static t_fill				*ft_free(t_fill *f)
{
	int		i;
	int		n;

	i = f->heigth;
	n = f->hepi;
	while (i--)
		free(f->bulle[i]);
	free(f->bulle);
	while (n--)
		free(f->piece[n]);
	free(f->piece);
	f->score = 2147483646;
	return (f);
}

static void					ft_print(int x, int y)
{
	ft_putnbr(x);
	ft_putchar(' ');
	ft_putnbr(y);
	ft_putchar('\n');
}

static t_fill				*ft_init_struct(t_fill *f)
{
	f->piece = NULL;
	f->x = -1;
	f->y = -1;
	f->score = 2147483646;
	f->tmpscore = 0;
	f->bulle = 0;
	f->player = 0;
	f->hepi = 0;
	f->wipi = 0;
	f->width = 0;
	f->heigth = 0;
	f->en = 0;
	f->error = 0;
	return (f);
}

static t_fill				*ft_get_info(t_fill *f, int x, int j, char *line)
{
	f = ft_size_map(line, f);
	get_next_line(0, &line);
	ft_strdel(&line);
	while (x < f->heigth)
	{
		get_next_line(0, &line);
		f = ft_init_bulle(line, f, x);
		ft_strdel(&line);
		x++;
	}
	get_next_line(0, &line);
	f = ft_size_piece(line, f);
	ft_strdel(&line);
	while (j < f->hepi)
	{
		get_next_line(0, &line);
		f->piece[j] = (char*)malloc(sizeof(char*) * f->wipi);
		f->piece[j] = ft_strncpy(f->piece[j], line, f->wipi);
		ft_strdel(&line);
		j++;
	}
	f->x = -1;
	f->y = -1;
	return (f);
}

int							main(void)
{
	t_fill		*f;
	char		*line;

	f = NULL;
	f = (t_fill*)malloc(sizeof(*f));
	f = ft_init_struct(f);
	line = NULL;
	get_next_line(0, &line);
	f->player = ft_player(line);
	f->en = f->player == -1 ? -2 : -1;
	ft_strdel(&line);
	while (1)
	{
		f = ft_get_info(f, 0, 0, line);
		f = ft_setup_resolve(f, f->en);
		f = ft_resolve(f, f->en);
		ft_print(f->x == -1 ? 0 : f->x, f->y == -1 ? 0 : f->y);
		f = ft_free(f);
		if (f->x == -1 && f->y == -1)
			break ;
	}
	return (0);
}
