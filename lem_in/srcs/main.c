/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 14:25:20 by thescriv          #+#    #+#             */
/*   Updated: 2018/10/18 14:49:38 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int		ft_start(t_lemin *lemin)
{
	if (!parser(lemin))
		return (0);
	if (!paths(lemin))
		return (0);
	if (!split_ants(lemin))
		return (0);
	if (!record(lemin))
		return (0);
	if (!display(lemin))
		return (0);
	return (1);
}

int				main(void)
{
	t_lemin lemin;

	if (ft_start(&lemin) == 0)
		ft_putstr("ERROR\n");
	return (0);
}
