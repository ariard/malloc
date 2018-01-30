/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_coalesce.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 20:32:17 by ariard            #+#    #+#             */
/*   Updated: 2018/01/31 00:11:59 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		*chunk_coalesce(t_area *ar, t_chunk *free, size_t req, char range)
{
	t_cand		cand;
	t_bins		bs;
	size_t		s_clean;

	bs = chunk_find(ar, (void *)free);
	req = (bs.a == 0) ? align(req, 16) : align(req, 512);
	while (bs.bin && bs.a < 2 && free)
	{
		s_clean = BT(free) & ~(1 << 0);
		cand = (t_cand) { free, 0, 0, 0 };
		if (range == 0 && bin_checkin(bs.bin, (void *)free, bs.a, -1))
			cand.backward = chunk_search(bs, (void *)free, req - s_clean,
				(t_ctrl){ 0, -1 });
		if (bin_checkin(bs.bin, (void *)free, bs.a, 1))
			cand.forward = chunk_search(bs, (void *)free, req - s_clean,
				(t_ctrl){ 0, 1 });
		cand.backward = (cand.forward + s_clean > req) ? 0 : cand.backward;
		cand.size = cand.forward + s_clean + cand.backward;
		free = (range == 0) ? free->next : NULL;
		if (cand.size > req)
			return (chunk_merge(bs.bin, cand.chunk, cand.forward
				+ (BT(cand.chunk) & ~(1 << 0)), cand.backward, bs.a));
	}
	return (NULL);
}
