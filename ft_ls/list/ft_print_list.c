/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tescriva <tescriva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 14:31:35 by tescriva          #+#    #+#             */
/*   Updated: 2019/08/29 14:17:23 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_block(t_lst *lst, t_ls *e)
{
	char	*tmp;

	tmp = ft_itoa(lst->val->stat.st_blocks);
	tmp[0] == '\0' ? ft_strdel(&tmp) : 0;
	tmp == NULL ? tmp = ft_strdup("0") : 0;
	ft_padding_info(tmp, e->size[0]);
	ft_strdel(&tmp);
	ft_printf(" ");
}

void	ft_print_list(t_lst *lst, t_ls *e)
{
	e->flag[L] || e->flag[S] ? ft_printf("total %d\n", e->total_block) : 0;
	if (e->flag[D])
	{
		ft_putstr(CYAN_L);
		ft_printf("%s", e->main_path);
		ft_putstr(NC);
	}
	else
	{
		lst = e->head;
		while (lst)
		{
			e->flag[S] ? ft_print_block(lst, e) : 0;
			e->flag[L] ? ft_print_perm(lst, e) : 0;
			ft_print_color(lst);
			e->flag[L] && S_ISLNK(lst->val->stat.st_mode) ?
				ft_print_symbolic(lst) : 0;
			e->flag[L] ? ft_putchar('\n') : 0;
			e->flag[UN] && lst->next != 0 ? ft_putchar('\n') : 0;
			lst = lst->next;
		}
		!e->flag[BIG_R] ? free_lst(e->head) : 0;
	}
}
