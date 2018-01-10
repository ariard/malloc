/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_merge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 19:33:14 by ariard            #+#    #+#             */
/*   Updated: 2018/01/10 21:27:09 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void	junc_freelist(t_chunk *tmp)
{
	if (tmp->next)
		(tmp->next)->prev = tmp->prev;
	if (tmp->prev)
		(tmp->prev)->next = tmp->next;
	tmp->next = NULL;
	tmp->prev = NULL;
}

void		*chunk_merge(void *chunk, size_t forward, size_t backward)
{
	t_chunk		*tmp;
	size_t		new_size;

	DBG(GREEN "chunk merge %zu %zu \n" RESET, forward, backward);
	new_size = forward + backward;
	tmp = (t_chunk *)chunk;
	while (forward)
	{
		junc_freelist(tmp);
		if ((forward -= (BT(tmp) & ~(1 << 0))) == 0)
			BT_FINAL(tmp) = SET_BUSY(new_size);
		else
			tmp = (t_chunk *)((void *)tmp + (BT(tmp) & ~(1 << 0)));
	}
	BT(chunk) = SET_BUSY(new_size);
	tmp = (t_chunk *)chunk;
	while (backward)
	{
		junc_freelist(tmp);
		if ((backward -= BT(tmp) & ~(1 << 0)) == 0)
			BT(tmp) = SET_BUSY(new_size);
		else
			tmp = ((void *)tmp - (BT_PREV(tmp) & ~(1 << 0)));
	}
	return (tmp);
}
