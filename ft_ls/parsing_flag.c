/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tescriva <tescriva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 15:48:13 by tescriva          #+#    #+#             */
/*   Updated: 2019/08/28 14:11:57 by tescriva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_flag_on(char c, t_ls *e)
{
	if (c == 'l' && e->flag[UN] == 0)
		e->flag[L] = 1;
	c == 'R' ? e->flag[BIG_R] = 1 : 0;
	c == 'a' ? e->flag[A] = 1 : 0;
	c == 'r' ? e->flag[R] = 1 : 0;
	c == 't' ? e->flag[T] = 1 : 0;
	c == 's' ? e->flag[S] = 1 : 0;
	if (c == '1')
	{
		e->flag[UN] = 1;
		e->flag[L] = 0;
	}
	c == 'd' ? e->flag[D] = 1 : 0;
	c == 'f' ? e->flag[F] = 1 : 0;
}

void	ft_get_flag(char *str, t_ls *e)
{
	int i;

	i = 0;
	if (str[i] == '-' && str[i + 1] == '-')
		return ;
	while (str[++i])
	{
		if (ft_chrstr("lRarts1dG", str[i]) == 1)
			ft_flag_on(str[i], e);
		else
			error(USAGE, str[i]);
	}
}
