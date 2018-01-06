/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pack_bin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 23:19:14 by ariard            #+#    #+#             */
/*   Updated: 2018/01/06 20:35:57 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*bin_pack(t_config *config, t_bin *bin, size_t request)
{
	t_chunk	*best;
	t_chunk	*tmp;
	size_t	size;

	DBG(RED "BIN PACK\n" RESET);
	tmp = bin->first;
	best = bin->first;
	size = bin->freespace;
	while (tmp)
	{
		if (*(size_t *)((void *)tmp - sizeof(size_t)) < size)
		{
			best = tmp;
			size = *(size_t *)((void *)tmp - sizeof(size_t));
		}
		tmp = tmp->next;
	}
	if (best->prev)
		(best->prev)->next = best->next;
	if (best->next)
		(best->next)->prev = best->prev;
	return (chunk_init(config, bin, best, request));
}
