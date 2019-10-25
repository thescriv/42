/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   folder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tescriva <tescriva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 12:33:45 by tescriva          #+#    #+#             */
/*   Updated: 2019/08/30 12:12:30 by tescriva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_get_size(t_lst *lst, t_ls *e)
{
	int		length;

	if ((length = ft_intlen(lst->val->stat.st_blocks)) > e->size[0])
		e->size[0] = length + 1;
	if ((length = ft_intlen(lst->val->stat.st_nlink)) > e->size[1])
		e->size[1] = length;
	if ((length = ft_strlen(lst->val->pw_name)) > e->size[2])
		e->size[2] = length + 1;
	if ((length = ft_strlen(lst->val->gr_name)) > e->size[3])
		e->size[3] = length + 1;
	if ((length = ft_intlen(lst->val->stat.st_size)) > e->size[4])
		e->size[4] = length;
}

char	*ft_check_path(t_ls *e, char *path)
{
	if ((e->path = ft_isdir(path)) == NULL)
		return (NULL);
	if (e->current_path == NULL)
	{
		if (e->main_path[0] == '/' && e->main_path[1] == '\0')
			return (ft_strdup(e->main_path));
		return (ft_strjoin(e->main_path, "/"));
	}
	return (ft_strjoinfree(e->current_path, "/"));
}

int		*ft_size_zero(int *tab)
{
	tab[0] = 0;
	tab[1] = 0;
	tab[2] = 2;
	tab[3] = 0;
	tab[4] = 0;
	tab[5] = 0;
	return (tab);
}

void	ft_get_folder(t_ls *e, t_lst *lst)
{
	e->total_block = 0;
	e->size = ft_size_zero(e->size);
	while ((e->dir = readdir(e->path)) != NULL)
	{
		if (e->dir->d_name[0] != '.' || (e->dir->d_name[0] == '.'
					&& e->flag[A]) || e->flag[F])
		{
			lst = create_node(e->dir->d_name, lst, e, &e->head);
			if (e->flag[L] && e->total_block != 0)
				ft_get_size(lst, e);
		}
	}
	closedir(e->path);
	ft_display_ls(e, e->head);
	ft_strdel(&e->current_path);
}
