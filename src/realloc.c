/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 23:13:19 by ariard            #+#    #+#             */
/*   Updated: 2018/01/18 21:59:47 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		*realloc(void *ptr, size_t size)
{
	t_bins		bs;
	t_cand		cand;
	void		*new;
	t_area		*ar;

	DBG(RED "REALLOC\n" RESET);
	ar = thread_set();
	if (!ptr || !((bs = chunk_find(ar, ptr)).bin))
		return (thread_unset(&ar->mutex, NULL));
	cand = (t_cand) { 0, 0, 0 };
	if (bs.a != 2 && bin_checkin(bs.bin, ptr, bs.a, 1))
		cand.forward = chunk_search(bs, ptr, BT(ptr) + size, 
			(t_ctrl) { (BT(ptr) & ~(1 << 0)), 1 });
	DBG("chunk found\n");
	new = NULL;
//	show_cand_merge(ptr, cand);
	if (bs.a != 2 && cand.forward > BT(ptr) + size)
	{
		DBG("inside\n"); 
		new = chunk_merge(ptr, cand.forward, 0);
		return (thread_unset(&ar->mutex, new));
	}
	new = _malloc(BT(ptr) + size);
	ft_memcpy(new, ptr, BT(ptr) - 2 * sizeof(size_t));
	_free(ptr);
	return (thread_unset(&ar->mutex, new));
}
