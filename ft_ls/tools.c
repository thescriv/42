/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 12:34:16 by thescriv          #+#    #+#             */
/*   Updated: 2019/08/29 15:39:51 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_padding_info(char *tmp, int size)
{
	int		length;

	length = size - ft_strlen(tmp);
	while (length >= 0)
	{
		ft_putchar(' ');
		length--;
	}
	ft_printf(tmp);
}

char	**sort_ascii(char **av, int i, int j)
{
	char	**tab;
	char	*tmp;

	while (av[j])
		j++;
	tab = (char**)malloc(sizeof(char*) * (j - i) + 1);
	j = i - 1;
	while (av[++j])
		tab[j - i] = ft_strdup(av[j]);
	tab[j - i] = NULL;
	j = -1;
	while (tab[++j])
	{
		if (tab[j + 1] && ft_strcmp(tab[j], tab[j + 1]) > 0)
		{
			tmp = ft_strdup(tab[j]);
			ft_strdel(&tab[j]);
			tab[j] = ft_strdup(tab[j + 1]);
			ft_strdel(&tab[j + 1]);
			tab[j + 1] = ft_strdup(tmp);
			ft_strdel(&tmp);
			j = -1;
		}
	}
	return (tab);
}

void	pre_sort_ascii(char **av, int i, t_ls *e, t_lst *lst)
{
	char **tab;

	tab = sort_ascii(av, i, i);
	i = 0;
	while (tab[i])
	{
		e->main_path = ft_strdup(tab[i]);
		if ((e->current_path = ft_check_path(e, e->main_path)) != NULL)
		{
			!e->flag[D] ? ft_printf("%s:\n", tab[i]) : 0;
			ft_get_folder(e, lst);
			!e->flag[D] && tab[i + 1] ? ft_printf("\n") : 0;
		}
		e->head = NULL;
		ft_strdel(&tab[i]);
		ft_strdel(&e->main_path);
		e->current_path = NULL;
		i++;
	}
	free(tab);
}

DIR		*ft_isdir(char *path)
{
	struct stat st;
	DIR			*dossier;

	if (stat(path, &st) == 0)
	{
		if (S_ISDIR(st.st_mode) != 1)
		{
			ft_printf("%s\n", path);
			return (NULL);
		}
	}
	if ((dossier = opendir(path)) == NULL)
	{
		ft_putstr_fd("ft_ls: ", 2);
		ft_putstr_fd(path, 2);
		if ((st.st_mode & S_IRUSR) == 0 && S_ISDIR(st.st_mode) == 1)
		{
			ft_putstr_fd(": Permission denied\n", 2);
			return (NULL);
		}
		ft_putstr_fd(": No such file or directory\n", 2);
		return (NULL);
	}
	if (S_ISDIR(st.st_mode) == 1)
		return (dossier);
	return (NULL);
}
