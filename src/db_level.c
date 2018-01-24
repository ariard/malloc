/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_level.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 19:30:14 by ariard            #+#    #+#             */
/*   Updated: 2018/01/24 20:01:34 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void	_level(int fd, char *s, va_list argp)
{
	static	int		lvl;

	if (lvl++ == 0)
		dprintf(fd, s, argp);
	lvl--;
}

void		level(int fd, char *s, ...)
{
	va_list	argp;

	va_start(argp, s);
	_level(fd, s, argp);
	va_end(argp);
}
