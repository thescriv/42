/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 14:17:31 by thescriv          #+#    #+#             */
/*   Updated: 2018/10/18 14:17:31 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	*add_path(t_pathlist *pathlist, t_path *path)
{
	t_path	*tmp;

	tmp = pathlist->start;
	if (!tmp)
	{
		pathlist->start = path;
		path->next = NULL;
		path->previous = NULL;
		return (pathlist);
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = path;
	path->previous = tmp;
	path->next = NULL;
	return (pathlist);
}
