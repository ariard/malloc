/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 18:49:55 by ariard            #+#    #+#             */
/*   Updated: 2018/01/06 20:29:20 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*chunk_init(t_config *config, t_bin *bin, t_chunk *chunk, size_t request)
{
	DBG(RED "CHUNK INIT\n" RESET);
	if (request < config->limit_small)
		bin->first = (request < config->limit_tiny) ? (bin->first + TINY(request)) \
			: (bin->first + SMALL(request));	
	*(size_t *)((void *)chunk - sizeof(size_t)) = request;
	*(size_t *)(bin->first - (2 * sizeof(size_t))) = request;
	bin->freespace -= (request < config->limit_tiny) ? TINY(request) \
			: SMALL(request);
	*(size_t *)(bin->first - sizeof(size_t)) = bin->freespace;
	return (chunk);
}
