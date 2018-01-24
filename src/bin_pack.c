/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pack_bin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 23:19:14 by ariard            #+#    #+#             */
/*   Updated: 2018/01/24 21:48:56 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*bin_pack(t_area *ar, t_bin *bin, size_t req)
{
	t_chunk	*best;
	t_chunk	*tmp;
	size_t	size;
	size_t	a_req;

	tmp = bin->first;
	if (bin->freespace - (a_req = (req <= g_cfg.limit_tiny) 
		? align(req, 16) : align(req, 512)) < 0)
		tmp = NULL;
	best = NULL;
	size = bin->freespace;
	while (tmp)
	{
		best = (BT(tmp) <= size && BT(tmp) >= a_req) ? tmp : best;
		size = (BT(tmp) <= size && BT(tmp) >= a_req) ? BT(tmp) : size;
		tmp = tmp->next;
	}
	if (best == NULL)
		best = chunk_coalesce(ar, bin->first, a_req, 0);
	return ((best) ? chunk_init(bin, best, a_req) : NULL);
}
