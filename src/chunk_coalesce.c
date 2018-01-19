/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_coalesce.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 20:32:17 by ariard            #+#    #+#             */
/*   Updated: 2018/01/19 18:58:47 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		*chunk_coalesce(t_area *ar, t_chunk *free, size_t req)
{
	t_cand		cand;
	t_bins		bs;

	bs = chunk_find(ar, (void *)free);
	if (!bs.bin)
		return (NULL);
	while (free)
	{
		cand = (t_cand) { free, 0, 0, 0 };
		if (bin_checkin(bs.bin, (void *)free, bs.a, -1))
			cand.backward = chunk_search(bs, (void *)free, req - BT(free),
				(t_ctrl){ 0, -1 });
		if (bin_checkin(bs.bin, (void *)free, bs.a, 1))
			cand.forward = chunk_search(bs, (void *)free, req - BT(free),
				(t_ctrl){ 0, 1 });
		cand.backward = (cand.forward + BT(free) > req) ? 0 : cand.backward;
		cand.size = cand.forward + BT(free) + cand.backward;
		free = free->next;
		if (cand.size > req)
			return (chunk_merge(cand.chunk, cand.forward
				+ BT(cand.chunk), cand.backward));
	}
	return (NULL);
}
