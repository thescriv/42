/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tescriva <tescriva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 17:50:01 by tescriva          #+#    #+#             */
/*   Updated: 2017/11/18 16:55:55 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*s;
	t_list	*l;

	l = *alst;
	if (!l)
		return ;
	while (l)
	{
		s = l->next;
		del(l->content, l->content_size);
		free(l);
		l = NULL;
		l = s;
	}
	*alst = NULL;
}
