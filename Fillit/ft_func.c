/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tescriva <tescriva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 22:57:18 by tescriva          #+#    #+#             */
/*   Updated: 2017/12/09 17:00:16 by tescriva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill.h"

int     ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        i++;
    }
    return (i);
}

void    ft_putchar(char c)
{
    write (1, &c, 1);
}

void    ft_putstr(char *str)
{
    write (1, str, ft_strlen(str));
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	unsigned char	k;
	int				i;

	k = (unsigned char)c;
	str = (unsigned char *)b;
	i = 0;
	while (len--)
		str[i++] = k;
	return (str);
}

void	*ft_memalloc(size_t size)
{
	void *tab;

	tab = (void *)malloc(sizeof(void) * size);
	return (tab ? ft_memset(tab, '.', size) : NULL);
}
