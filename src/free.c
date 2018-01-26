/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 21:17:14 by ariard            #+#    #+#             */
/*   Updated: 2018/01/26 19:28:37 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void		add_freechk(t_bins bins, void *ptr)	
{
	t_chunk		*listfree;

	listfree = (bins.bin->first) ? bins.bin->first : NULL;
	((t_chunk *)ptr)->next = listfree;
	((t_chunk *)ptr)->prev = NULL;
	if (listfree)
		listfree->prev = ptr;
	bins.bin->first = ptr;
	chunk_set(SET_FREE(*(size_t *)((void *)ptr - sizeof(size_t))),
		(t_chunk *)ptr);
}

void			free(void *ptr)
{
	t_area		*ar;
	t_bins		bs;
	size_t		b_size;

	//DBG(GREEN "FREE\n" RESET);
	pthread_once(&g_cfg.once, malloc_init);	
	ar = thread_set();
	bin_check(ar);
	if (chunk_check(ar, ptr)) 
	{
		if (getenv("MallocErrorAbort"))
			chunk_error(ptr, 0);
	}	
	else if (ptr)
	{
		logmem(ptr, 1, ar);
		bs = chunk_find(ar, ptr);
		bs.bin->freespace += (BT(ptr) & ~(1 << 0));
		b_size = (bs.a == 0) ? g_cfg.tiny_area : g_cfg.small_area;
		b_size = (bs.a == 2) ? BT(ptr) + sizeof(t_bin) : b_size;
		if (bs.a == 2 || bs.bin->freespace == b_size)
		{
			if (bs.prev)
				bs.prev = bs.bin->next;
			munmap(bs.bin, b_size);
		}
		else
			add_freechk(bs, ptr);
	}
	thread_unset2(ar); 
}
