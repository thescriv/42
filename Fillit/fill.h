/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tescriva <tescriva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 22:53:47 by tescriva          #+#    #+#             */
/*   Updated: 2017/12/20 14:19:51 by tescriva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct  s_list
{
    /*void x[4];
    void y[4];*/
    struct s_list *next;
}               t_list;


char    **ft_del(char **fill, int let);
char    *ft_solve(char **tab, char *fill, int y, int i, int n);
void    ft_prep_to_resolve(char **tab, int np, int n);
void	*ft_memalloc(size_t size);
void	*ft_memset(void *b, int c, size_t len);
int     ft_error(int i);
void	ft_check_str(char *tmp, int p);
void	ft_tetriminos(char **tab, int np);
char    **ft_strsplit(const char *tab, char c, int i);
char 	*ft_check_tetriminos(char *tab, int lettre);
void    ft_putstr(char *str);
void    ft_putchar(char c);
int     ft_strlen(char *str);
void    ft_display(char *tab, int square, int x);
