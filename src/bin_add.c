/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_bin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 23:06:56 by ariard            #+#    #+#             */
/*   Updated: 2018/01/07 20:24:46 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_bin	*bin_add(size_t request)
{
	t_bin			*bin;
	size_t			size;

	DBG(RED "BIN_ADD\n" RESET);
	size = (request <= area.cfg->limit_tiny) ? area.cfg->tiny_area \
		: area.cfg->small_area;
	size = (request > area.cfg->limit_tiny) ? request \
		+ sizeof(t_bin) + sizeof(size_t) : size;
	// warning if mmap send trash
	bin = mmap(0, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	bin->next = NULL;
	bin->freespace = size - sizeof(t_bin);
	bin->first = bin + 1;
	*(size_t *)(bin->first) = bin->freespace;
	bin->first = bin->first + sizeof(size_t);
	((t_chunk *)bin->first)->prev = NULL;
	((t_chunk *)bin->first)->next = NULL;
	return (bin);
}
