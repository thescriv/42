/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tescriva <tescriva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 15:02:36 by tescriva          #+#    #+#             */
/*   Updated: 2017/12/26 18:35:38 by tescriva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fill.h"

int ft_place(char *tab, char *fill, int n)
{
    int i;
    int p;

    i = 0;
    while (tab[i] != '\0')
    {
        while (tab[i] == '.' && tab[i] == '\n')
            i++;
    }
    return (1);
}

int ft_solve(char **tab, char *fill, int x, int let)
{
    int i;
    int n;

    i = 0;
    n = 0;
    if (tab[let] == NULL)
        ft_display(fill);
    while (tab[let][i])
    {
        tab[let][i] == '\n' ? i++ : 0;
        if (fill[n] == '.')
        {
            if (ft_place(tab[let], fill, n))
            {

            }
        }
        n++;
        i++;
    }
}
