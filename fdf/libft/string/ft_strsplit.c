/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:24:52 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/12 18:43:10 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int			ft_mot(char const *s, char c)
{
	int		n;
	int		i;

	i = 0;
	n = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		s[i] != '\0' ? n++ : 0;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (n);
}

static char			*ft_fill(char const *s, char c, int i)
{
	int		k;
	char	*mot;

	k = i;
	while (s[k] != c && s[k] != '\0')
		k++;
	mot = (char *)malloc(sizeof(char) * (k + 1));
	if (!mot)
		return (NULL);
	k = 0;
	while (s[i] != c && s[i] != '\0')
		mot[k++] = s[i++];
	mot[k] = '\0';
	return (mot);
}

char				**ft_strsplit(char const *s, char c)
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
	n = ft_mot(s, c);
	tab = (char **)malloc(sizeof(tab) * (n + 1));
	if (!tab)
		return (NULL);
	while (++j < n)
	{
		while (s[i] == c)
			i++;
		tab[j] = ft_fill(s, c, i);
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	tab[j] = NULL;
	return (tab);
}
