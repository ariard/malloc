/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 21:17:14 by ariard            #+#    #+#             */
/*   Updated: 2018/02/02 20:19:06 by ariard           ###   ########.fr       */
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

	pthread_once(&g_cfg.once, malloc_init);	
	pthread_mutex_lock(&debug);
	write(3, "f - flag A : ", 13);
	print_value(3, (unsigned long)pthread_self());
	write(3, "\n", 1);
	pthread_mutex_unlock(&debug);
	ar = thread_set();
	bin_check(ar);
	pthread_mutex_lock(&debug);
	write(3, "f - flag B : ", 13);
	print_value(3, (unsigned long)pthread_self());
	write(3, "\n", 1);
	pthread_mutex_unlock(&debug);
	if (!ptr || chunk_check(ar, ptr))
	{
		pthread_mutex_lock(&debug);
		write(3, "f - flag C : ", 13);
		print_value(3, (unsigned long)pthread_self());
		write(3, "\n", 1);
		pthread_mutex_unlock(&debug);
		if (g_cfg.error)
			chunk_error(ptr, 0);
	}
	else if (ptr)
	{
		pthread_mutex_lock(&debug);
		write(3, "f - flag D : ", 13);
		print_value(3, (unsigned long)pthread_self());
		write(3, "\n", 1);
		pthread_mutex_unlock(&debug);
		logmem(ptr, 1, ar);
		bs = chunk_find(ar, ptr);
		bs.bin->freespace += (BT(ptr) & ~(1 << 0));
		b_size = (bs.a == 0) ? g_cfg.tiny_area : g_cfg.small_area;
		b_size = (bs.a == 2) ? BT(ptr) + sizeof(t_bin) : b_size;
		bs.bin->nb--;
		if (bs.a == 2 || bs.bin->freespace == b_size)
		{
			if (bs.prev)
				bs.prev = bs.bin->next;
			else
				ar->list[2] = bs.bin->next;
			munmap(bs.bin, b_size);
		}
		else
			add_freechk(bs, ptr);
	}
	thread_unset2(ar); 
	pthread_mutex_lock(&debug);
	write(3, "f - flag E : ", 13);
	print_value(3, (unsigned long)pthread_self());
	write(3, "\n", 1);
	pthread_mutex_unlock(&debug);
}
