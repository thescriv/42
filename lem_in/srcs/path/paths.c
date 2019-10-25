/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 14:17:54 by thescriv          #+#    #+#             */
/*   Updated: 2018/10/18 14:17:54 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	paths(t_lemin *l)
{
	t_pathlist	*paths;

	if (!(paths = init_pathlist()))
		return (0);
	map_dead_nodes(l);
	if (!(paths = find_pathlist(l, paths)))
		return (0);
	if (!paths->start)
		return (0);
	if (!(fill_paths(l, paths)))
		return (0);
	return (1);
}
