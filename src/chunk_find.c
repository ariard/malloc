/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_find.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 23:21:43 by ariard            #+#    #+#             */
/*   Updated: 2018/01/09 18:30:13 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_bins		chunk_find(void *ptr)
{	
	t_bin	*bin;
	t_bin	*prev;
	size_t	max;
	char	a;

	max = (BT(ptr) > area.cfg.limit_tiny) ? area.cfg.small_area \
		: area.cfg.tiny_area;
	max = (BT(ptr) > area.cfg.limit_small) ? BT(ptr) : max;
	bin = (max > area.cfg.tiny_area) ? area.list[1] : area.list[0];
	bin = (max > area.cfg.small_area) ? area.list[2] : bin;
	prev = NULL;
	a = (BT(ptr) > area.cfg.limit_tiny) ? 1 : 0;
	a = (BT(ptr) > area.cfg.limit_small) ? 2: a;
	while (bin)
	{
		if (((char *)bin - (char *)ptr) < 0 \
			&& ((char *)bin + max - (char *)ptr > 0))
			return ((t_bins){ bin, prev, a});
		prev = bin;
		bin = bin->next;
	}
	return ((t_bins){ NULL, NULL, -1 });
}
