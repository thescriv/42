/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 10:57:04 by thescriv          #+#    #+#             */
/*   Updated: 2018/09/24 18:01:16 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdio.h>
# include "../libft/gnl/get_next_line.h"
# include "../libft/libft.h"

typedef struct		s_fill
{
	char	**piece;
	int		x;
	int		y;
	int		**bulle;
	int		score;
	int		tmpscore;
	int		player;
	int		width;
	int		heigth;
	int		wipi;
	int		hepi;
	int		en;
	int		error;
}					t_fill;

int					ft_player(char *line);
t_fill				*ft_size_map(char *line, t_fill *f);
t_fill				*ft_init_bulle(char *line, t_fill *f, int x);
t_fill				*ft_size_piece(char *line, t_fill *f);
t_fill				*ft_setup_resolve(t_fill *f, int en);
t_fill				*ft_resolve(t_fill *f, int en);

#endif
