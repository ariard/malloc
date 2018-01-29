/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_merge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 19:33:14 by ariard            #+#    #+#             */
/*   Updated: 2018/01/30 00:19:57 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void	clean_chunk(t_chunk *tmp)
{
	size_t		size;

	if (tmp->next && (tmp->next)->prev)
		(tmp->next)->prev = tmp->prev;
	write(3, "cm - flag 1\n", 12);
	if (tmp->prev && (tmp->prev)->next)
		(tmp->prev)->next = tmp->next;
	tmp->next = NULL;
	tmp->prev = NULL;
	write(3, "cm - flag 2\n", 12);
	size = BT(tmp) & ~(1 << 0);
	print_value(3, size);
	write(3, "\n", 1);
	SUM(tmp) = 0;
	write(3, "cm - flag 3\n", 12);
	LSUM(tmp, size) = 0;
	write(3, "cm - flag 4\n", 12);
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
		write(3, "cm - flag 0\n", 12);
		clean_chunk(tmp);
		write(3, "cm - flag A\n", 12);
		if ((forward -= (BT(tmp) & ~(1 << 0))) == 0)
			break;
		tmp = ((void *)tmp + (BT(tmp) & ~(1 << 0)));
		write(3, "cm - flag B\n", 12);
		bin->nb--;	
		write(3, "cm - flag C\n", 12);
	}
	write(3, "cm - flag D\n", 12);
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
