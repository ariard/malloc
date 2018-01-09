/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_coalesce.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 20:32:17 by ariard            #+#    #+#             */
/*   Updated: 2018/01/09 20:45:46 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		*chunk_coalesce(t_chunk *free, size_t req)
{
	t_cand		best;
	t_cand		cand;
	t_bins		bs;

	best.size = 0;
	if ((!(bs = chunk_find((void *)free)).bin))
		return (NULL);
	while (free)
	{
		if (bin_checkin(bs.bin, (void *)free, bs.a, -1))
			cand.backward = chunk_search(bs, (void *)free, req,
				(t_ctrl){ BT(free), -1 });
		if (bin_checkin(bs.bin, (void *)free, bs.a, 1))
			cand.forward = chunk_search(bs, (void *)free, req,
				(t_ctrl){ BT(free), 1 });
		cand.size = cand.forward + cand.backward - 2 * BT(free);
		if ((cand.size < req) && (cand.size < best.size || best.size == 0))
			best = cand;
		free = free->next;
	}
	//if (best.size)
	//	return (chunk_merge(free, cand.forward, cand.backward - BT(free)));
	return (NULL);
}
