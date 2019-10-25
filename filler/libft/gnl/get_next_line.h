/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tescriva <tescriva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 13:59:19 by tescriva          #+#    #+#             */
/*   Updated: 2018/09/24 18:02:56 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft.h"

# define BUFF_SIZE 1

typedef struct	s_gnl
{
	char			*str;
	size_t			fd;
	struct s_gnl	*next;
}				t_gnl;

int				get_next_line(const int fd, char **line);
#endif
