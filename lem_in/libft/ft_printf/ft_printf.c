/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 14:43:57 by thescriv          #+#    #+#             */
/*   Updated: 2018/10/18 14:43:57 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	t_printf p;

	ft_bzero(&p, sizeof(t_printf));
	p.format = format;
	va_start(p.ap, format);
	ft_text_parser(&p);
	va_end(p.ap);
	return ((p.error != -1) ? p.len : -1);
}
