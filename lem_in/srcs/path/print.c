/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 14:17:56 by thescriv          #+#    #+#             */
/*   Updated: 2018/10/18 14:17:56 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_path(t_path *path)
{
	ft_printf("----------\n");
	ft_printf("ENDED = %d\n", path->ended);
	ft_printf("CURR = %d\n", path->curr);
	ft_printf("NCHILDS = %d\n", path->childs);
	ft_printf("LENGTH = %d\n", path->nodes->length);
	ft_printf("ADRESS    = %p\n", path);
	ft_printf("NEXT      = %p\n", path->next);
	ft_printf("PREVIOUS  = %p\n", path->previous);
	print_nodelist(path->nodes);
	ft_printf("----------\n");
}

void	print_nodelist(t_nodelist *nl)
{
	t_node *tmp;

	tmp = nl->start;
	while (tmp)
	{
		if (tmp->next)
			ft_printf("%d->", tmp->nb);
		else
			ft_printf("%d\n", tmp->nb);
		tmp = tmp->next;
	}
}

void	print_path_list(t_pathlist *pl)
{
	t_path	*tmp;
	int		i;

	i = 0;
	tmp = pl->start;
	ft_printf("-------------PATHLIST------------\n");
	while (tmp)
	{
		ft_printf("Path %d :\n", i);
		i++;
		print_path(tmp);
		tmp = tmp->next;
	}
	ft_printf("-------------END PATHlIST-----------\n");
}
