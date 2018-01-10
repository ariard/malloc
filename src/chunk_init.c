/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 18:49:55 by ariard            #+#    #+#             */
/*   Updated: 2018/01/10 18:29:41 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int		align(int x, int f)
{
	if ((x + 16) % 16 != 0)
		return ((x + 16) + (f - (x + 16) % f));
	return (x + 16);
}

void	*chunk_init(t_bin *bin, t_chunk *chunk, size_t request)
{
	size_t	a_req;
	size_t	next_bt;
	t_chunk	*tmp;

	//DBG(RED "CHUNK INIT\n" RESET);
	tmp = NULL;
	a_req = (request <= area.cfg.limit_tiny) ? align(request, 16) :
		align(request, 512);
	next_bt = (BT(chunk) & ~(1 << 0)) - a_req;
	if ((int)(bin->freespace - a_req) < 0)
		return (NULL);
	bin->freespace -= a_req;
	BT(chunk) = SET_BUSY(a_req);
	BT_FINAL(chunk) = SET_BUSY(a_req);
	if (bin_checkin(bin, chunk, (request <= area.cfg.limit_tiny) ? 0 : 1, 1))
	{
		if (bin->first && ((t_chunk *)bin->first)->next)
			tmp = ((t_chunk *)bin->first)->next;
		bin->first = (void *)chunk + a_req;
		((t_chunk *)bin->first)->next = tmp;
		BT(bin->first) = next_bt;
		BT_FINAL(bin->first) = next_bt;
	}
	return (chunk);
}
