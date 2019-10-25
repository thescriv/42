/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tescriva <tescriva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 18:49:56 by tescriva          #+#    #+#             */
/*   Updated: 2019/08/28 20:56:04 by tescriva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_ls.h"

void	ft_print_color(t_lst *lst)
{
	if (S_ISDIR(lst->val->stat.st_mode))
		ft_putstr(CYAN_L);
	else if (S_ISLNK(lst->val->stat.st_mode))
		ft_putstr(PURPLE);
	else if (S_IXUSR & lst->val->stat.st_mode)
		ft_putstr(RED);
	else if (S_ISSOCK(lst->val->stat.st_mode))
		ft_putstr(GREEN);
	ft_printf("%s ", lst->val->name);
	ft_putstr(NC);
}

void	free_lst(t_lst *lst)
{
	t_lst *tmp;

	while (lst)
	{
		tmp = lst->next;
		lst->val->path ? ft_strdel(&lst->val->path) : 0;
		lst->val->name ? ft_strdel(&lst->val->name) : 0;
		lst->val->pw_name ? ft_strdel(&lst->val->pw_name) : 0;
		lst->val->gr_name ? ft_strdel(&lst->val->gr_name) : 0;
		if (lst->val)
		{
			free(lst->val);
			lst->val = NULL;
		}
		if (lst)
		{
			free(lst);
			lst = NULL;
		}
		if (tmp)
			lst = tmp;
	}
}

void	ft_display_ls(t_ls *e, t_lst *lst)
{
	t_lst *tmp;

	ft_print_list(lst, e);
	!e->flag[L] ? ft_putchar('\n') : 0;
	if (e->flag[BIG_R])
	{
		tmp = e->head;
		lst = e->head;
		while (lst)
		{
			if (S_ISDIR(lst->val->stat.st_mode)
					&& lst->val->name[0] != '.' && lst->val->name[1] != '\0')
			{
				e->head = NULL;
				ft_printf("\n%s:\n", lst->val->path);
				e->size = ft_size_zero(e->size);
				ft_strdel(&e->current_path);
				e->current_path = ft_strjoin(lst->val->path, "/");
				if ((e->path = ft_isdir(lst->val->path)) != NULL)
					ft_get_folder(e, NULL);
			}
			lst = lst->next;
		}
		free_lst(tmp);
	}
}
