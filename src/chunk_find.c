/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_find.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 23:21:43 by ariard            #+#    #+#             */
/*   Updated: 2018/01/24 23:57:57 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_bins		chunk_find(t_area *ar, void *ptr)
{
	t_bin	*bin;
	t_bin	*prev;
	size_t	max;
	char	a;

	max = (BT(ptr) > g_cfg.limit_tiny) ? g_cfg.small_area \
		: g_cfg.tiny_area;
	max = (BT(ptr) > g_cfg.limit_small) ? BT(ptr) : max;
	bin = (max > g_cfg.tiny_area) ? ar->list[1] : ar->list[0];
	bin = (max > g_cfg.small_area) ? ar->list[2] : bin;
	prev = NULL;
	a = (BT(ptr) > g_cfg.limit_tiny) ? 1 : 0;
	a = (BT(ptr) > g_cfg.limit_small) ? 2 : a;
	while (bin)
	{
		if (((char *)bin - (char *)ptr) < 0 \
			&& ((char *)bin + max - (char *)ptr > 0))
			return ((t_bins){ bin, prev, a});
		prev = bin;
		bin = bin->next;
	}
	write(3, "cf - flag A\n", 12);
	return ((t_bins){ NULL, NULL, -1 });
}
