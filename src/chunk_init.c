/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 18:49:55 by ariard            #+#    #+#             */
/*   Updated: 2018/01/08 23:12:30 by ariard           ###   ########.fr       */
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

	//DBG(RED "CHUNK INIT\n" RESET);
	a_req = (request <= area.cfg.limit_tiny) ? align(request, 16) : align(request, 512);
	if ((int)(bin->freespace - a_req) < 0)
		return (NULL);
	bin->freespace -= a_req;
	bin->first += a_req;
	BT(chunk) = SET_BUSY(a_req);
	//*(size_t *)(bin->first - (2 * sizeof(size_t))) = SET_BUSY(request);
	BT_FINAL(chunk) = SET_BUSY(a_req);
	BT(bin->first) = bin->freespace;
	return (chunk);
}
