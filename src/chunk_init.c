/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 18:49:55 by ariard            #+#    #+#             */
/*   Updated: 2018/01/26 21:48:57 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void		set_freelist(void **first, t_chunk *chunk)
{
	if (!chunk->prev && !chunk->next)
		*first = NULL;
	if (chunk->prev && (chunk->prev)->next)
		(chunk->prev)->next = chunk->next;
	else
		*first = chunk->next;
	if (chunk->next && (chunk->next)->prev)
		(chunk->next)->prev = chunk->prev;
	chunk->next = NULL;
	chunk->prev = NULL;
}

void			*chunk_init(t_bin *bin, t_chunk *chunk, size_t a_req)
{
	size_t	s_split;
	t_chunk	*split;
	t_chunk	*listfree;

	set_freelist(&bin->first, chunk);
	s_split = (BT(chunk) & ~(1 << 0)) - a_req;
	if (!(s_split = (s_split < 48) ? 0 : s_split))
		a_req += s_split;
	bin->freespace -= a_req;
	chunk_set(SET_BUSY(a_req), chunk);
	bin->nb++;
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
