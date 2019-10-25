/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tescriva <tescriva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 19:20:46 by tescriva          #+#    #+#             */
/*   Updated: 2018/11/14 18:17:28 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <math.h>

# define HEIGTH 600
# define WIDTH 800

typedef struct	s_data
{
	void		*jpg;
	int			*data;
	int			len;
	int			bpp;
}				t_data;

typedef struct	s_fdf
{
	void		*ptr;
	void		*wnd;
	char		**tab;
	int			**map;
	int			sp;
	int			move;
	int			right;
	int			left;
	int			h;
	int			w;
	t_data		i;
	int			e;
	int			x;
	int			y;
	int			z;
	int			proj;
	int			dx;
	int			dy;
	int			rgb;
	int			index;
	int			color;
	int			reset;
	int			rotate;
	int			j;
	int			x1;
	int			y1;
	int			x2;
	int			y2;
}				t_fdf;

void			ft_ready_draw(t_fdf *f);
int				get_key(int key, void *param);
void			ft_proj_iso(t_fdf *f);
void			ft_proj_para(t_fdf *f);

#endif
