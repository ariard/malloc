/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_merge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 19:33:14 by ariard            #+#    #+#             */
/*   Updated: 2018/01/19 19:39:25 by ariard           ###   ########.fr       */
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

static void	fuck_norme(size_t new_size, t_chunk *tmp)
{
	*(size_t *)((void *)tmp + (*(size_t *)((void *)tmp - sizeof(size_t))
		& ~(1 << 0)) - 2 * sizeof(size_t)) = SET_BUSY(new_size);
}

void		*chunk_merge(void *chunk, size_t forward, size_t backward)
{
	t_chunk		*tmp;
	size_t		new_size;

	new_size = forward + backward;
	tmp = (t_chunk *)chunk;
	while (forward)
	{
		junc_freelist(tmp);
		if ((forward -= (BT(tmp) & ~(1 << 0))) == 0)
			fuck_norme(new_size, tmp);
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
