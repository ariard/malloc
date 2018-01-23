/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_bin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 23:06:56 by ariard            #+#    #+#             */
/*   Updated: 2018/01/23 20:22:33 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_bin	*bin_add(size_t request)
{
	t_bin			*bin;
	size_t			size;

	size = (request <= g_cfg.limit_tiny) ? g_cfg.tiny_area \
		: g_cfg.small_area;
	size = (request > g_cfg.limit_small) ? request \
		+ sizeof(t_bin) + 2 * sizeof(size_t) : size;
	if ((bin = mmap(0, size, PROT_READ | PROT_WRITE, MAP_ANON
		| MAP_PRIVATE, -1, 0)) == MAP_FAILED)
		return (NULL);
	bin->next = NULL;
	bin->freespace = size - sizeof(t_bin);
	bin->first = bin + 1;
	*(size_t *)(bin->first) = bin->freespace;
	write(3, "flag [A]\n", 9);
	*(size_t *)((char *)bin->first + bin->freespace - sizeof(size_t)) = bin->freespace;
	write(3, "flag [B]\n", 9);
	bin->first = bin->first + sizeof(size_t);
	((t_chunk *)bin->first)->prev = NULL;
	((t_chunk *)bin->first)->next = NULL;
	return (bin);
}
