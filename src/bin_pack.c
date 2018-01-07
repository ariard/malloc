/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pack_bin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 23:19:14 by ariard            #+#    #+#             */
/*   Updated: 2018/01/07 22:50:09 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*bin_pack(t_bin *bin, size_t request)
{
	t_chunk	*best;
	t_chunk	*tmp;
	size_t	size;

	DBG(RED "BIN PACK\n" RESET);
	if (request > area.cfg->limit_small)
		return (bin->first);
	tmp = bin->first;
	best = bin->first;
	size = bin->freespace;
	while (tmp)
	{
		best = (BT(tmp) < size) ? tmp : best;
		size = (BT(tmp) < size) ? BT(tmp) : size;
		tmp = tmp->next;
	}
	if (size == bin->freespace && !(best = chunk_coalesce(bin, bin->first, request)))
		return (NULL);
	if (best->prev)
		(best->prev)->next = best->next;
	if (best->next)
		(best->next)->prev = best->prev;
	return (chunk_init(bin, best, request));
}
