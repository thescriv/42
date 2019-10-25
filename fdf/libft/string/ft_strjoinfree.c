/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 12:18:03 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/12 18:44:47 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoinfree(char *to_free, char const *s2)
{
	int		size;
	int		i;
	int		j;
	char	*tmp;

	if (!to_free || !s2)
		return (NULL);
	i = -1;
	j = -1;
	tmp = ft_strdup(to_free);
	free(to_free);
	size = (int)ft_strlen(tmp) + (int)ft_strlen(s2);
	to_free = (char *)malloc(sizeof(char) * (size + 1));
	if (!to_free)
		return (NULL);
	while (tmp[++i] != '\0')
		to_free[i] = tmp[i];
	while (s2[++j] != '\0')
		to_free[i + j] = s2[j];
	to_free[size] = '\0';
	free(tmp);
	return (&to_free[0]);
}
