/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_bin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 23:06:56 by ariard            #+#    #+#             */
/*   Updated: 2018/01/06 22:28:48 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_bin	*bin_add(t_config *config, size_t request)
{
	t_bin			*bin;
	int				size;

	DBG(RED "BIN_ADD\n" RESET);
	size = (request < config->limit_tiny) ? config->tiny_area : config->small_area;
	// warning if mmap send trash
	bin = mmap(0, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	bin->next = NULL;
	bin->freespace = size;
	DBG("freespace %d\n", size);
	bin->first = bin + 1;
	*(size_t *)(bin->first) = bin->freespace;
	bin->first = bin->first + sizeof(size_t);
	((t_chunk *)bin->first)->prev = NULL;
	((t_chunk *)bin->first)->next = NULL;
//	bin->freespace -= sizeof(t_bin) * 2;
	return (bin);
}
