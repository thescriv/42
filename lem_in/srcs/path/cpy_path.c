/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 14:17:39 by thescriv          #+#    #+#             */
/*   Updated: 2018/10/18 14:17:39 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	cpy_path(t_path *src, t_path *dest, t_node *node)
{
	dest->nodes = cpy_nodelist(src->nodes, dest->nodes);
	dest->curr = src->curr;
	dest->ended = src->ended;
	if (node)
		add_node(dest->nodes, node);
	return (1);
}
