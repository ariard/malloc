/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 18:49:55 by ariard            #+#    #+#             */
/*   Updated: 2018/01/24 22:05:43 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void			*chunk_init(t_bin *bin, t_chunk *chunk, size_t a_req)
{
	size_t	s_split;
	t_chunk	*split;
	t_chunk	*listfree;

	if (!chunk->prev && !chunk->next)
		bin->first = NULL;
	if (chunk->prev)
		(chunk->prev)->next = chunk->next;
	if (chunk->next)
		(best->next)->prev = chunk->prev;
	s_split = (BT(chunk) & ~(1 << 0)) - a_req;
	bin->freespace -= a_req;
	set_chunk(a_req, chunk);
	if (s_split)
	{
		split = (void *)chunk + a_req;
		set_chunk(s_split, split);
		listfree = bin->first;	
		split->next = listfree;	
		if (listfree)
			listfree->prev = split;
		bin->first = split;
	}
	return (chunk);
}
