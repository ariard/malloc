/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 18:49:55 by ariard            #+#    #+#             */
/*   Updated: 2018/01/25 00:35:35 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void			*chunk_init(t_bin *bin, t_chunk *chunk, size_t a_req)
{
	size_t	s_split;
	t_chunk	*split;
	t_chunk	*listfree;

	write(3, "chk_init\n", 9);
	print_addr(bin);
	print_addr(chunk);
	print_addr(chunk->prev);
	if (!chunk->prev && !chunk->next)
		bin->first = NULL;
	write(3, "ci - flag A\n", 12);
	if (chunk->prev)
		(chunk->prev)->next = chunk->next;
	write(3, "ci - flag B\n", 12);
	if (chunk->next)
		(chunk->next)->prev = chunk->prev;
	write(3, "ci - flag B\n", 12);
	s_split = (BT(chunk) & ~(1 << 0)) - a_req;
	bin->freespace -= a_req;
	chunk_set(SET_BUSY(a_req), chunk);
	if (s_split)
	{
		split = (void *)chunk + a_req;
		chunk_set(s_split, split);
		listfree = (bin->first) ? bin->first : NULL;
		split->next = listfree;	
		split->prev = NULL;
		if (listfree)
			listfree->prev = split;
		bin->first = split;
	}
	return (chunk);
}
