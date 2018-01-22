/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 18:49:55 by ariard            #+#    #+#             */
/*   Updated: 2018/01/23 00:21:14 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int				align(int x, int f)
{
	if ((x + 16) % 16 != 0)
		return ((x + 16) + (f - (x + 16) % f));
	return (x + 16);
}

static void		fuck_norme1(size_t a_req, t_chunk *chunk)
{
	BT(chunk) = SET_BUSY(a_req);
	*(size_t *)((void *)chunk + (*(size_t *)((void *)chunk - sizeof(size_t))
		& ~(1 << 0)) - 2 * sizeof(size_t)) = SET_BUSY(a_req);
}

static void		fuck_norme2(size_t next_bt, void *first)
{
	BT(first) = next_bt;
	*(size_t *)((void *)first + (*(size_t *)((void *)first - sizeof(size_t))
		& ~(1 << 0)) - 2 * sizeof(size_t)) = next_bt;
}

void			*chunk_init(t_bin *bin, t_chunk *chunk, size_t request)
{
	size_t	a_req;
	size_t	next_bt;
	t_chunk	*tmp;

	tmp = NULL;
	a_req = (request <= g_cfg.limit_tiny) ? align(request, 16) :
		align(request, 512);
	next_bt = (BT(chunk) & ~(1 << 0)) - a_req;
	if ((int)(bin->freespace - a_req) < 0)
		return (NULL);
	bin->freespace -= a_req;
	fuck_norme1(a_req, chunk);
	if (next_bt)
	{
		if (bin->first && !(BT(bin->first) & 1))
			tmp = (t_chunk *)bin->first;
		bin->first = (void *)chunk + a_req;
		if ((((t_chunk *)bin->first)->next = tmp))
			tmp->prev = ((t_chunk *)bin->first);
		((t_chunk *)bin->first)->prev = NULL;
		fuck_norme2(next_bt, bin->first);
	}
	return (chunk);
}
