/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_bin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 23:06:56 by ariard            #+#    #+#             */
/*   Updated: 2018/01/06 20:31:31 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_bin	*bin_add(t_config *config, size_t request)
{
	struct s_chunk	*chunk;
	t_bin			*bin;
	int				size;

	DBG(RED "BIN_ADD\n" RESET);
	bin = NULL;
	if (request < config->limit_tiny)
		size = config->tiny_area;
	else if (request < config->limit_small)
		size = config->small_area;	
	else
		size = request;
	bin = mmap(0, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE,
		-1, 0);
	bin->next = NULL;
	bin->freespace = size;
	bin->first = bin + 1;
	*(size_t *)(bin->first) = bin->freespace;
	bin->first = bin->first + sizeof(size_t);
	chunk = bin->first;
	chunk->prev = NULL;
	chunk->next = NULL;
//	bin->freespace -= sizeof(t_bin) * 2;
	return (bin);
}
