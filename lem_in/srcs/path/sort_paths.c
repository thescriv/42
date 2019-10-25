/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 14:17:58 by thescriv          #+#    #+#             */
/*   Updated: 2018/10/18 14:17:58 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	swap(t_path **a, t_path **b)
{
	int			tmpcurr;
	int			tmpchilds;
	t_nodelist	*tmpnodes;
	int			tmpended;

	tmpcurr = (*b)->curr;
	tmpchilds = (*b)->childs;
	tmpnodes = (*b)->nodes;
	tmpended = (*b)->ended;
	(*b)->curr = (*a)->curr;
	(*b)->childs = (*a)->childs;
	(*b)->nodes = (*a)->nodes;
	(*b)->ended = (*a)->ended;
	(*a)->curr = tmpcurr;
	(*a)->childs = tmpchilds;
	(*a)->nodes = tmpnodes;
	(*a)->ended = tmpended;
}

void	sort_paths(t_pathlist *paths, int (*comp)(t_path *p1, t_path *p2))
{
	t_path			*tmp;
	t_path			*tmpsort;

	tmp = paths->start;
	while (tmp->next)
	{
		if (comp(tmp, tmp->next))
		{
			tmpsort = tmp->next;
			swap(&tmp, &tmpsort);
			tmp = paths->start;
		}
		tmp = tmp->next;
	}
}
