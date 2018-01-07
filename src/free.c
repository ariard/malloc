/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 21:17:14 by ariard            #+#    #+#             */
/*   Updated: 2018/01/07 23:58:12 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void		bin_inspect(t_bin *list, void *ptr, size_t max, size_t sizeptr)
{
	t_bin		*prev;
	t_chunk		*freechunk;

	DBG(GREEN "BIN INSPECT\n" RESET);
	while (list)
	{
		// MACRO HERE
		if (((char *)list - (char *)ptr) < 0 \
			&& ((char *)list + max - (char *)ptr) > 0)
		{
			if (max <= area.cfg->limit_small)
			{
				freechunk = list->first;
				while (freechunk->next && (freechunk = freechunk->next));
				freechunk->next = ptr;
				list->freespace += (max >= area.cfg->limit_tiny) ? \
					TINY(sizeptr) : SMALL(sizeptr);
				// clean boundary there
			}
			if (list->freespace == max || max > area.cfg->limit_small)
			{
				DBG("clean bin");
				prev->next = list->next;
				munmap(list, max);
				break;
			}
		}
		prev = list;
		list = list->next;
	}
}

void			free(void *ptr)
{
	t_bin 	*list_bin;
	size_t	max;

	DBG(GREEN "FREE\n" RESET);
	if (!ptr)
		return;
	DBG("size ptr is %zu\n", *(size_t *)(ptr - sizeof(size_t)));
	max = (BT(ptr) > area.cfg->limit_tiny) ? area.cfg->small_area \
		: area.cfg->tiny_area;
	max = (BT(ptr) > area.cfg->limit_small) ? BT(ptr) : max;
	list_bin = (max > area.cfg->tiny_area) ? area.small : area.tiny;
	list_bin = (max > area.cfg->small_area) ? area.large : list_bin;
	bin_inspect(list_bin, ptr, max, BT(ptr));
	BT(ptr) = SET_FREE(BT(ptr));
	BT_FINAL(ptr) = SET_FREE(BT(ptr));
}
