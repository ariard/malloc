/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_coalesce.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 20:32:17 by ariard            #+#    #+#             */
/*   Updated: 2018/01/08 23:56:47 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_agg		wrapper_check(t_chunk *list, size_t request, t_wrapper wp)
{
	size_t	i;

	i = (request > area.cfg.limit_tiny) ? area.cfg.small_area \
		: area.cfg.tiny_area;
	if ((wp.lvl < 0 \
		&& (char *)list - sizeof(t_bin) - sizeof(size_t) - (char *)wp.bin <= 0)
		|| (wp.lvl > 0 \
		&& (char *)wp.bin + i - ((char *)list + BT(list) + sizeof(size_t)) <= 0))
		return (chunk_check(list, request, wp));
	return ((struct s_agg){ wp.lvl, BT(list) + 16 + wp.sum });
}

t_agg		chunk_check(t_chunk *list, size_t request, t_wrapper wp)
{
	t_chunk		*chunk;

	chunk = (wp.lvl < 0) ? PREV(list) : NEXT(list);
	if (BUSY(chunk))
	{
		if (BT(chunk) + 16 + wp.sum > request)
			return ((struct s_agg){ wp.lvl, BT(chunk) + 16 + wp.sum });
		else if (wp.lvl < 0)
			return (wrapper_check(chunk, request, \
				(struct s_wp){ BT(chunk) + 16 + wp.sum, wp.lvl - 1, wp.bin }));
		else if (wp.lvl > 0)
			return (wrapper_check(chunk, request, \
				(struct s_wp){ BT(chunk) + 16 + wp.sum, wp.lvl + 1, wp.bin }));
	}
	return ((struct s_agg){ wp.lvl, BT(chunk) + 16 + wp.sum });
}

void		*chunk_coalesce(t_bin *bin, t_chunk *list, size_t request)
{
	t_cand		best;
	t_cand		cand;

	best.size = 0;
	while (list)
	{
		cand.backward = chunk_check(list, request, \
			(struct s_wp){ BT(list), -1, bin });
		cand.forward = chunk_check(list, request, \
			(struct s_wp){ BT(list), 1, bin });
		cand.size = -16 * cand.backward.nb + cand.backward.size + 16
			* cand.forward.nb + cand.forward.size + BT(list);
		if ((cand.size < request) && (cand.size < best.size || best.size == 0))
			best = cand;
		list = list->next;
	}
	return (NULL);
	//return (coalesce(list, cand));
}
