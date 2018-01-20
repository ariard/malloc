/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 21:17:14 by ariard            #+#    #+#             */
/*   Updated: 2018/01/20 01:02:08 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void		fuck_norme1(void *ptr)
{
	BT(ptr) = SET_FREE(*(size_t *)((void *)ptr - sizeof(size_t)));
	*(size_t *)((void *)ptr + (*(size_t *)((void *)ptr - sizeof(size_t))
		& ~(1 << 0)) - 2 * sizeof(size_t)) = BT(ptr);
}

static void		fuck_norme2(void *ptr)
{
	*(size_t *)((void *)ptr + (*(size_t *)((void *)ptr - sizeof(size_t))
		& ~(1 << 0)) - 2 * sizeof(size_t)) = BT(ptr);
}

void			free(void *ptr)
{
	t_bins		bs;
	t_chunk		*freechunk;
	size_t		a_size;
	t_area		*ar;

	ar = thread_set();
	if (!ptr || !((bs = chunk_find(ar, ptr)).bin))
		return (thread_unset2(&ar->mutex));
	bs.bin->freespace += (BT(ptr) & ~(1 << 0));
	a_size = (bs.a == 0) ? g_cfg.tiny_area : g_cfg.small_area;
	a_size = (bs.a == 2) ? BT(ptr) + sizeof(t_bin) : a_size;
	if (bs.a == 2 || bs.bin->freespace == a_size)
	{
		if (bs.prev)
			bs.prev = bs.bin->next;
		munmap(bs.bin, a_size);
	}
	freechunk = bs.bin->first;
	while (freechunk->next)
		freechunk = freechunk->next;
	((t_chunk*)ptr)->next = NULL;
	((t_chunk*)ptr)->prev = freechunk;
	freechunk->next = ptr;
	fuck_norme1(ptr);
	thread_unset(&ar->mutex, NULL);
}

void			p_free(void *ptr)
{
	t_bins		bs;
	t_chunk		*freechunk;
	size_t		a_size;
	t_area		*ar;

	ar = pthread_getspecific(g_cfg.key);
	if (!ptr || !((bs = chunk_find(ar, ptr)).bin))
		return ;
	bs.bin->freespace += (BT(ptr) & ~(1 << 0));
	a_size = (bs.a == 0) ? g_cfg.tiny_area : g_cfg.small_area;
	a_size = (bs.a == 2) ? BT(ptr) + sizeof(t_bin) : a_size;
	if (bs.a == 2 || bs.bin->freespace == a_size)
	{
		if (bs.prev)
			bs.prev = bs.bin->next;
		munmap(bs.bin, a_size);
	}
	freechunk = bs.bin->first;
	while (freechunk->next)
		freechunk = freechunk->next;
	((t_chunk*)ptr)->next = NULL;
	((t_chunk*)ptr)->prev = freechunk;
	freechunk->next = ptr;
	BT(ptr) = SET_FREE(*(size_t *)((void *)ptr - sizeof(size_t)));
	fuck_norme2(ptr);
}
