/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 23:13:19 by ariard            #+#    #+#             */
/*   Updated: 2018/01/20 00:13:36 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		*realloc(void *ptr, size_t size)
{
	t_bins		bs;
	t_cand		cand;
	void		*new;
	t_area		*ar;

	if (!ptr && !size)
		return (NULL);
	ar = thread_set();
	if (ptr && !((bs = chunk_find(ar, ptr)).bin))
		return (thread_unset(&ar->mutex, NULL));
	cand = (t_cand) { NULL, 0, 0, 0 };
	if (ptr && bs.a != 2 && bin_checkin(bs.bin, ptr, bs.a, 1))
		cand.forward = chunk_search(bs, ptr, BT(ptr) + size,
			(t_ctrl) { (BT(ptr) & ~(1 << 0)), 1 });
	new = NULL;
	if (ptr && bs.a != 2 && cand.forward > BT(ptr) + size)
	{
		new = chunk_merge(ptr, cand.forward, 0);
		return (thread_unset(&ar->mutex, new));
	}
	new = (ptr) ? p_malloc(BT(ptr) + size) : p_malloc(size);
	if (ptr)
		ft_memcpy(new, ptr, BT(ptr) - 2 * sizeof(size_t));
	if (new)
		p_free(ptr);
	return (thread_unset(&ar->mutex, new));
}
