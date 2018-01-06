/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_bin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 23:06:56 by ariard            #+#    #+#             */
/*   Updated: 2018/01/06 23:32:30 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_bin	*bin_add(t_config *config, size_t request)
{
	t_bin			*bin;
	size_t			size;

	DBG(RED "BIN_ADD\n" RESET);
	size = (request < config->limit_tiny) ? config->tiny_area : config->small_area;
	// warning if mmap send trash
	bin = mmap(0, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	bin->next = NULL;
	DBG("size %zu\n", size);
	bin->freespace = size - sizeof(t_bin);
	DBG("freespace %zu\n", bin->freespace);
	bin->first = bin + 1;
	*(size_t *)(bin->first) = bin->freespace;
	bin->first = bin->first + sizeof(size_t);
	((t_chunk *)bin->first)->prev = NULL;
	((t_chunk *)bin->first)->next = NULL;
//	bin->freespace -= sizeof(t_bin) * 2;
	return (bin);
}
