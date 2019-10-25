/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 12:43:16 by thescriv          #+#    #+#             */
/*   Updated: 2018/09/24 18:03:55 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

int			ft_player(char *line)
{
	int p;

	p = 0;
	line = ft_strchr(line, 'p');
	line++;
	p = ft_atoi(line);
	p = p == 1 ? -1 : -2;
	return (p);
}

t_fill		*ft_size_map(char *line, t_fill *f)
{
	int i;

	i = 0;
	get_next_line(0, &line);
	while (ft_isdigit(line[i]) == 0)
		i++;
	f->heigth = ft_atoi(line + i);
	while (ft_isdigit(line[i]) == 1)
		i++;
	i++;
	f->width = ft_atoi(line + i);
	f->bulle = (int**)malloc(sizeof(int*) * f->heigth);
	ft_strdel(&line);
	return (f);
}

t_fill		*ft_init_bulle(char *line, t_fill *f, int x)
{
	int i;
	int n;

	n = 0;
	i = 0;
	while (ft_isdigit(line[i]) == 1)
		i++;
	i++;
	f->bulle[x] = (int*)malloc(sizeof(int) * f->width);
	while (line[i])
	{
		if (line[i] == 'O' || line[i] == 'o')
			f->bulle[x][n] = -1;
		else if (line[i] == 'X' || line[i] == 'x')
			f->bulle[x][n] = -2;
		else if (line[i] == '.')
			f->bulle[x][n] = 0;
		i++;
		n++;
	}
	return (f);
}

t_fill		*ft_size_piece(char *line, t_fill *f)
{
	int i;

	i = 0;
	while (ft_isdigit(line[i]) == 0)
		i++;
	f->hepi = ft_atoi(line + i);
	while (ft_isdigit(line[i]) == 1)
		i++;
	f->wipi = ft_atoi(line + i);
	f->piece = (char**)malloc(sizeof(char*) * f->hepi + 1);
	return (f);
}
