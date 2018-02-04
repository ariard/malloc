/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_bin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 23:06:56 by ariard            #+#    #+#             */
/*   Updated: 2018/02/04 14:45:12 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_bin			*bin_add(size_t request)
{
	t_bin			*bin;
	size_t			size;

	size = (request <= g_cfg.limit_tiny) ? g_cfg.tiny_area \
		: g_cfg.small_area;
	size = (request > g_cfg.limit_small) ? request \
		+ sizeof(t_bin) + 2 * sizeof(size_t) + 2 * sizeof(int) + 24 : size;
	if ((bin = mmap(0, size, PROT_READ | PROT_WRITE, MAP_ANON
		| MAP_PRIVATE, -1, 0)) == MAP_FAILED)
		bin = (g_cfg.error) ? chunk_error(0, 3) : NULL;
	else
	{
		bin->next = NULL;
		bin->nb = 0;
		bin->freespace = size - sizeof(t_bin);
		bin->first = bin + 1;
		bin->first = bin->first + sizeof(int) + sizeof(size_t);
		chunk_set(bin->freespace, (t_chunk *)bin->first);
		((t_chunk *)bin->first)->prev = NULL;
		((t_chunk *)bin->first)->next = NULL;
	}
	return (bin);
}
