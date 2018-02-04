/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_level.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 19:30:14 by ariard            #+#    #+#             */
/*   Updated: 2018/02/04 16:52:14 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void	in_level(int fd, char *s, va_list argp)
{
	static	int		lvl;

	if (lvl++ == 0)
		ft_dprintf(fd, s, argp);
	lvl--;
}

void		level(int fd, char *s, ...)
{
	va_list	argp;

	va_start(argp, s);
	in_level(fd, s, argp);
	va_end(argp);
}
