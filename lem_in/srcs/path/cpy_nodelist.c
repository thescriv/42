/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_nodelist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 14:17:36 by thescriv          #+#    #+#             */
/*   Updated: 2018/10/18 14:17:37 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_nodelist	*cpy_nodelist(t_nodelist *src, t_nodelist *dest)
{
	t_node		*tmp;

	dest->length = 0;
	tmp = src->start;
	while (tmp)
	{
		add_node(dest, new_node(tmp->nb));
		tmp = tmp->next;
	}
	return (dest);
}
