/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_merge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 19:33:14 by ariard            #+#    #+#             */
/*   Updated: 2018/01/24 22:28:06 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void	clean_chunk(t_chunk *tmp)
{
	size_t		size;

	if (tmp->next)
		(tmp->next)->prev = tmp->prev;
	if (tmp->prev)
		(tmp->prev)->next = tmp->next;
	tmp->next = NULL;
	tmp->prev = NULL;
	size = BT(tmp);
	SUM(tmp) = 0;
	LSUM(tmp, size) = 0;
}

void		*chunk_merge(t_bin *bin, 
		t_chunk *chunk, size_t forward, size_t backward)
{
	t_chunk		*tmp;
	size_t		new_size;

	new_size = forward + backward;
	tmp = chunk;
	while (forward)
	{
		clean_chunk(tmp);
		if ((forward -= (BT(tmp) & ~(1 << 0))) == 0)
			break;
		tmp = ((void *)tmp + (BT(tmp) & ~(1 << 0)));
		bin->nb--;	
	}
	tmp = chunk;
	while (backward)
	{
		clean_chunk(tmp);
		if ((backward -= BT(tmp) & ~(1 << 0)) == 0)
			break;
		tmp = ((void *)tmp - (LT_PREV((void *)tmp) & ~(1 << 0)));
		bin->nb--;
	}
	bin->nb++;
	chunk_set(new_size, tmp);
	return (tmp);
}
