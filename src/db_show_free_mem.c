/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_read_freelist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 20:36:57 by ariard            #+#    #+#             */
/*   Updated: 2018/01/19 18:38:37 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "malloc.h"

void			show_free_chunk(void)
{
	t_bin		*bin;
	t_chunk		*chunk;
	size_t		total;
	int			a;

	a = -1;
	total = 0;
	while (++a != 2 && !(bin = ar->list[a]))
		;
	while (bin)
	{
		area_print(bin, a);
		chunk = bin->first;
		while (chunk)
		{
			ft_printf("%p - %p : %zu octets\n", chunk, (char *)chunk
				+ BT(chunk), BT(chunk));
			total += BT(chunk);
			chunk = chunk->next;
		}
		if (!(bin = bin->next))
			while (++a != 2 && !(bin = ar->list[a]))
				;
	}
	ft_printf("Total : %zu octets\n", total);
}