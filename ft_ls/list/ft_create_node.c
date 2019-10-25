/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tescriva <tescriva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 14:55:44 by tescriva          #+#    #+#             */
/*   Updated: 2019/08/29 14:13:52 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

t_lst	*ft_list_add(t_lst **head, t_lst *lst, t_lst *tmp, t_ls *e)
{
	if (*head == NULL)
	{
		*head = tmp;
		return (*head);
	}
	return (ft_insert_node(head, lst, tmp, e));
}

t_info	*fill_data(t_info *data, t_ls *e)
{
	struct passwd	*passwd;
	struct group	*group;

	data->pw_name = NULL;
	data->gr_name = NULL;
	data->path = ft_strjoin(e->current_path, data->name);
	if (lstat(data->path, &data->stat) == -1)
		return (NULL);
	if (e->flag[L] || e->flag[T])
	{
		passwd = getpwuid(data->stat.st_uid);
		group = getgrgid(data->stat.st_gid);
		data->pw_name = passwd != NULL ? ft_strdup(passwd->pw_name) :
			(ft_itoa(data->stat.st_uid));
		data->gr_name = group != NULL ? ft_strdup(group->gr_name) :
			(ft_itoa(data->stat.st_gid));
		if (data->pw_name == NULL || data->gr_name == NULL)
			return (NULL);
		e->flag[T] ? data->clock = ctime(&data->stat.st_mtimespec.tv_sec) : 0;
	}
	return (data);
}

t_lst	*create_node(char *name, t_lst *lst, t_ls *e, t_lst **head)
{
	t_info	*data;
	t_lst	*tmp;

	if ((data = (t_info*)malloc(sizeof(t_info))) == NULL
			|| (tmp = (t_lst*)malloc(sizeof(t_lst))) == NULL
			|| (data->name = ft_strdup(name)) == NULL
			|| (data = fill_data(data, e)) == NULL)
		return (NULL);
	tmp->val = data;
	tmp->next = NULL;
	e->total_block += tmp->val->stat.st_blocks;
	return (ft_list_add(head, lst, tmp, e));
}
