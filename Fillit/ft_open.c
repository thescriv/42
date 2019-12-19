/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 16:37:49 by thescriv          #+#    #+#             */
/*   Updated: 2017/12/11 13:37:42 by tescriva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill.h"

void ft_display(char *tab, int square, int x)
{
    int y;
    int n;

    y = 0;
    while (y != square)
    {
        n = 0;
        while (n != x)
        {
            ft_putchar(tab[y]);
            y++;
            n++;
        }
        ft_putchar('\n');
    }
}

int 	ft_error(int i)
{
	if (i == 1)
	{
		ft_putstr("error\n");
		exit(0);
	}
	if (i == 2)
	{
		//usage//
	}
    return (0);
}

void	ft_check_str(char *tmp, int p)
{
	int i;
	int ligne;
	int dot;
	int diese;

	diese = 0;
	dot = 0;
	ligne = 0;
	i = -1;
	while (tmp[++i])
	{

		if (tmp[i] == '.' || tmp[i] == '#')
			tmp[i] == '.' ? dot++ : diese++;
		tmp[i] == '\n' ? ligne++ : 0;
	}
	if (p * 4 != diese || p * 12 != dot || ligne % 5 != 4 )
		ft_error(1);
}

int main(int argc, char **argv)
{
    int i;
    int fd;
	int octet;
	char buf[1];
	char temporaire[545];
    char **tab;

    i = 0;
    (void)argc;
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        return (0);
	while ((octet = read(fd, buf, 1)))
	{
		temporaire[i] = buf[0];
		i > 545 ? ft_error(3) : i++;
	}
	temporaire[i] = '\0';
	i = i / 21;
	ft_check_str(temporaire, i + 1);
	tab = ft_strsplit(temporaire, '\n', i);
    ft_tetriminos(tab, i);
    close(fd);
    return (0);
}
