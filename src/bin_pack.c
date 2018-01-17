/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pack_bin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 23:19:14 by ariard            #+#    #+#             */
/*   Updated: 2018/01/18 00:04:43 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*bin_pack(t_area *ar, t_bin *bin, size_t req)
{
	t_chunk	*best;
	t_chunk	*tmp;
	size_t	size;
	size_t	a_req;

//	DBG(RED "BIN PACK %d\n" RESET, (int)pthread_self());
	if (req > cfg.limit_small)
		return (bin->first);
	tmp = bin->first;
	best = NULL;
	size = bin->freespace;
	a_req = (req <= cfg.limit_tiny) ? align(req, 16) : align(req, 512);
	while (tmp)
	{
		best = (BT(tmp) <= size && BT(tmp) >= a_req) ? tmp : best;
		size = (BT(tmp) <= size && BT(tmp) >= a_req) ? BT(tmp) : size;
		tmp = tmp->next;
	}
	if (best == NULL && !(best = chunk_coalesce(ar, bin->first, a_req)))
		return (NULL);
	if (best->prev)
		(best->prev)->next = best->next;
	if (best->next)
		(best->next)->prev = best->prev;
	return (chunk_init(bin, best, req));
}
