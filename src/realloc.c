/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 23:13:19 by ariard            #+#    #+#             */
/*   Updated: 2018/01/23 19:38:03 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		*realloc(void *ptr, size_t size)
{
	t_bins		bs;
	t_cand		cand;
	void		*new;
	t_area		*ar;

	write(3, "realloc\n", 8);
	if (!ptr && !size)
		return (NULL);
	pthread_once(&g_cfg.once, malloc_init);
	ar = thread_set();
	if (ptr && !((bs = chunk_find(ar, ptr)).bin))
		return (thread_unset(&ar->mutex, NULL));
	write(3, "flag [A]\n", 9);
	if (ptr && !chunk_verify(ptr))
		return (thread_unset(&ar->mutex, NULL));
	write(3, "flag [B]\n", 8);
	cand = (t_cand) { NULL, 0, 0, 0 };
	if (ptr && bs.a != 2 && bin_checkin(bs.bin, ptr, bs.a, 1))
		cand.forward = chunk_search(bs, ptr, BT(ptr) + size,
			(t_ctrl) { (BT(ptr) & ~(1 << 0)), 1 });
	if (ptr && bs.a != 2 && cand.forward > BT(ptr) + size)
	{
		new = chunk_merge(ptr, cand.forward, 0);
		return (thread_unset(&ar->mutex, new));
	}
	new = (ptr) ? p_malloc(ar, BT(ptr) + size) : p_malloc(ar, size);
	if (ptr)
		ft_memcpy(new, ptr, BT(ptr) - 2 * sizeof(size_t));
	if (new)
		p_free(ar, ptr);
	return (thread_unset(&ar->mutex, new));
}
