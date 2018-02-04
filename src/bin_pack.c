/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pack_bin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 23:19:14 by ariard            #+#    #+#             */
/*   Updated: 2018/02/04 15:47:09 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void	*if_big(t_bin *bin, size_t req)
{
	bin->freespace -= req;
	return (bin->first);
}

void		*bin_pack(t_area *ar, t_bin *bin, size_t req)
{
	t_chunk	*cand;
	t_chunk	*tmp;
	size_t	size;
	size_t	a_req;

	cand = NULL;
	if (req <= g_cfg.limit_small)
	{
		a_req = (req <= g_cfg.limit_tiny) ? align(req, 16) : align(req, 512);
		a_req = (a_req < 48) ? 48 : a_req;
		tmp = ((int)(bin->freespace - a_req) < 0) ? NULL : bin->first;
		size = bin->freespace;
		while (tmp)
		{
			cand = (BT(tmp) <= size && BT(tmp) >= a_req) ? tmp : cand;
			size = (BT(tmp) <= size && BT(tmp) >= a_req) ? BT(tmp) : size;
			tmp = tmp->next;
		}
		cand = (!cand && ((int)bin->freespace - a_req > 0))
			? chunk_coalesce(ar, bin->first, a_req, 0) : cand;
		cand = (cand) ? chunk_init(bin, cand, a_req) : NULL;
	}
	else if (bin->freespace > req)
		cand = if_big(bin, req);
	return ((void *)cand);
}
