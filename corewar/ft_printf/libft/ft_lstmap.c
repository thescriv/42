/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 19:07:07 by vduong            #+#    #+#             */
/*   Updated: 2018/12/06 12:50:39 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*tmp;
	t_list	*start;

	if (lst && f)
	{
		tmp = f(lst);
		new = ft_lstnew(tmp->content, tmp->content_size);
		if (!new)
			return (NULL);
		lst = lst->next;
		start = new;
		while (lst)
		{
			tmp = f(lst);
			new->next = ft_lstnew(tmp->content, tmp->content_size);
			if (!new->next)
				return (NULL);
			new = new->next;
			lst = lst->next;
		}
		return (start);
	}
	return (NULL);
}
