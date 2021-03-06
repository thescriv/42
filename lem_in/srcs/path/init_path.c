/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 14:17:50 by thescriv          #+#    #+#             */
/*   Updated: 2018/10/18 14:17:50 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path		*init_path(void)
{
	t_path *p;

	if (!(p = (t_path*)malloc(sizeof(t_path))))
		return (NULL);
	p->curr = 0;
	p->childs = 0;
	if (!(p->nodes = init_nodelist()))
		return (NULL);
	p->ended = 0;
	p->next = NULL;
	p->previous = NULL;
	return (p);
}

t_pathlist	*init_pathlist(void)
{
	t_pathlist *pl;

	if (!(pl = (t_pathlist *)malloc(sizeof(t_pathlist))))
		return (NULL);
	pl->start = NULL;
	return (pl);
}

t_path		*new_path(t_path *path, int nodenb)
{
	t_path		*new;
	t_node		*node;

	if (nodenb != -1)
	{
		if (!(node = new_node(nodenb)))
			return (NULL);
	}
	else
		node = NULL;
	if (!(new = init_path()))
		return (NULL);
	if (!path)
	{
		new->curr = nodenb;
		add_node(new->nodes, node);
		new->ended = 0;
	}
	else
		cpy_path(path, new, node);
	new->curr = nodenb;
	return (new);
}
