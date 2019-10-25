/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 14:17:29 by thescriv          #+#    #+#             */
/*   Updated: 2018/10/18 14:17:30 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_nodelist	*add_node(t_nodelist *nodelist, t_node *node)
{
	t_node		*tmp;
	int			i;

	tmp = nodelist->start;
	if (!tmp)
	{
		nodelist->start = node;
		nodelist->start->index = 0;
		nodelist->length++;
		return (nodelist);
	}
	i = 0;
	while (tmp->next)
	{
		tmp = tmp->next;
		i++;
	}
	node->index = i;
	tmp->next = node;
	nodelist->length++;
	return (nodelist);
}
