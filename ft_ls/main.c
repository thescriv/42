/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tescriva <tescriva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 15:36:41 by tescriva          #+#    #+#             */
/*   Updated: 2019/08/29 15:39:32 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	error(int err, char c)
{
	if (err == USAGE)
	{
		ft_putstr_fd("ft_ls: illegal option -- ", 2);
		ft_putchar_fd(c, 2);
		ft_putchar_fd('\n', 2);
		ft_putendl_fd("usage: ft_ls [-lRarts1dG] [file ...]", 2);
	}
	exit(1);
}

int		ft_init_struct(t_ls *e)
{
	e->flag[0] = 0;
	e->flag[1] = 0;
	e->flag[2] = 0;
	e->flag[3] = 0;
	e->flag[4] = 0;
	e->flag[5] = 0;
	e->flag[6] = 0;
	e->flag[7] = 0;
	e->flag[8] = 0;
	e->flag[9] = 0;
	e->head = NULL;
	e->current_path = NULL;
	if ((e->size = (int*)malloc(sizeof(int) * 6)) == NULL)
		return (0);
	return (1);
}

int		ft_start(char **av, int ac, t_ls *e, t_lst *lst)
{
	int		i;

	lst = ft_memalloc(sizeof(t_lst));
	if (ft_init_struct(e) == 0)
		return (0);
	i = av[1] ? 0 : -1;
	while (av[++i] && av[i][0] == '-' && av[i][1] != '-' && av[i][1] != '\0')
		ft_get_flag(av[i], e);
	if (av[i] && av[i][0] == '-' && av[i][1] == '-' && av[i][2] != '\0')
		error(12, '-');
	av[i] && av[i][0] == '-' && av[i][1] == '-' ? i++ : 0;
	if (ac >= i && av[i] && av[i + 1])
		pre_sort_ascii(av, i, e, lst);
	else
	{
		e->main_path = !av[i] || i == 0 ? ft_strdup(".") : ft_strdup(av[i]);
		if ((e->current_path = ft_check_path(e, e->main_path)) != NULL)
			ft_get_folder(e, lst);
	}
	free(e->size);
	ft_strdel(&e->main_path);
	free(lst);
	return (1);
}

int		main(int ac, char **av)
{
	t_ls	e;
	t_lst	lst;

	ft_start(av, ac, &e, &lst);
	return (0);
}
