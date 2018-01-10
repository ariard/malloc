/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_coalesce.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 20:32:17 by ariard            #+#    #+#             */
/*   Updated: 2018/01/10 22:16:30 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		*chunk_coalesce(t_chunk *free, size_t req)
{
	t_cand		best;
	t_cand		cand;
	t_bins		bs;

	best.size = 0;
	bs = chunk_find((void *)free);
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
		if ((cand.size > req) && (cand.size < best.size || best.size == 0))
			best = cand;
		free = free->next;
	}
	if (best.size)
		return (chunk_merge(best.chunk, best.forward + BT(best.chunk), best.backward));
	return (NULL);
}
