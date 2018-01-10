/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_coalesce.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 20:32:17 by ariard            #+#    #+#             */
/*   Updated: 2018/01/10 18:26:18 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		*chunk_coalesce(t_chunk *free, size_t req)
{
	t_cand		best;
	t_cand		cand;
	t_bins		bs;

	//DBG("chunk coalesce\n");
	best.size = 0;
	if ((!(bs = chunk_find((void *)free)).bin))
		return (NULL);
	while (free)
	{
		cand.chunk = free;
		if (bin_checkin(bs.bin, (void *)free, bs.a, -1))
			cand.backward = chunk_search(bs, (void *)free, req,
				(t_ctrl){ BT(free), -1 });
		if (bin_checkin(bs.bin, (void *)free, bs.a, 1))
			cand.forward = chunk_search(bs, (void *)free, req,
				(t_ctrl){ cand.backward, 1 });
		cand.size = cand.forward + cand.backward;
		if ((cand.size > req) && (cand.size < best.size || best.size == 0))
			best = cand;
		free = free->next;
	}
	if (best.size)
		return (chunk_merge(best.chunk, best.forward, best.backward));
	return (NULL);
}
