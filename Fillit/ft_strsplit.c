/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:24:52 by thescriv          #+#    #+#             */
/*   Updated: 2017/12/06 16:56:38 by tescriva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill.h"

static char	*ft_fill(char const *s, char c, int i, char *tab)
{
	int		k;
	char	*mot;

	mot = (char *)malloc(sizeof(char) * (21));
	tab = (char *)malloc(sizeof(char) * (21));
	if (!tab || !mot)
		return (NULL);
	k = 0;
	while (k != 21)
		mot[k++] = s[i++];
	mot[k] = '\0';
	tab = mot;
	return (tab);
}

char	**ft_strsplit(char const *s, char c, int p)
{
	char	**tab;
	int		i;
	int		n;
	int		j;

	i = 0;
	n = 0;
	j = -1;
	if (!s)
		return (NULL);
	tab = (char **)malloc(sizeof(tab) * (p + 2));
	if (!tab)
		return (NULL);
	while (++j != p + 1)
	{
		tab[j] = ft_fill(s, c, i, tab[j]);
		i = i + 21;
	}
	tab[j] = 0;
	return (tab);
}
