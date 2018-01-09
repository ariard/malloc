/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_coalesce.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 20:32:17 by ariard            #+#    #+#             */
/*   Updated: 2018/01/09 19:38:47 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

//t_agg		wrapper_check(t_chunk *list, size_t request, t_wrapper wp)
//{
//	size_t	i;
//
//	i = (request > area.cfg.limit_tiny) ? area.cfg.small_area \
//		: area.cfg.tiny_area;
//	if ((wp.lvl < 0 \
//		&& (char *)list - sizeof(t_bin) - sizeof(size_t) - (char *)wp.bin <= 0)
//		|| (wp.lvl > 0 \
//		&& (char *)wp.bin + i - ((char *)list + BT(list) + sizeof(size_t)) <= 0))
//		return (chunk_check(list, request, wp));
//	return ((struct s_agg){ wp.lvl, BT(list) + 16 + wp.sum });
//}

//void		*chunk_coalesce(t_bin *bin, t_chunk *list, size_t request)
//{
//	t_cand		best;
//	t_cand		cand;
//
//	best.size = 0;
//	while (list)
//	{
//		cand.backward = chunk_check(list, request, \
//			(struct s_wp){ BT(list), -1, bin });
//		cand.forward = chunk_check(list, request, \
//			(struct s_wp){ BT(list), 1, bin });
//		cand.size = -16 * cand.backward.nb + cand.backward.size + 16
//			* cand.forward.nb + cand.forward.size + BT(list);
//		if ((cand.size < request) && (cand.size < best.size || best.size == 0))
//			best = cand;
//		list = list->next;
//	}
//	return (NULL);
//	//return (coalesce(list, cand));
//}

//t_agg		chunk_check(t_chunk *list, size_t request, t_wrapper wp)
//{
//	t_chunk		*chunk;
//
//	chunk = (wp.lvl < 0) ? PREV(list) : NEXT(list);
//	if (BUSY(chunk))
//	{
//		if (BT(chunk) + 16 + wp.sum > request)
//			return ((struct s_agg){ wp.lvl, BT(chunk) + 16 + wp.sum });
//		else if (wp.lvl < 0)
//			return (wrapper_check(chunk, request, \
//				(struct s_wp){ BT(chunk) + 16 + wp.sum, wp.lvl - 1, wp.bin }));
//		else if (wp.lvl > 0)
//			return (wrapper_check(chunk, request, \
//				(struct s_wp){ BT(chunk) + 16 + wp.sum, wp.lvl + 1, wp.bin }));
//	}
//	return ((struct s_agg){ wp.lvl, BT(chunk) + 16 + wp.sum });
//}

void		*chunk_coalesce(t_chunk *free, size_t req)
{
	t_cand		best;
	t_cand		cand;
	t_bins		bs;

	best.size = 0;
	if (!(bs = chunk_find(ptr).bin))
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
