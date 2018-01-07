/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 18:49:55 by ariard            #+#    #+#             */
/*   Updated: 2018/01/07 20:14:24 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*chunk_init(t_bin *bin, t_chunk *chunk, size_t request)
{
	DBG(RED "CHUNK INIT\n" RESET);
	if ((int)(bin->freespace - ((request <= area.cfg->limit_tiny) ? TINY(request) \
		: SMALL(request))) < 0)
		return (NULL);
	bin->freespace -= (request <= area.cfg->limit_tiny) ? TINY(request) \
			: SMALL(request);
	bin->first = (request <= area.cfg->limit_tiny) ? (bin->first + TINY(request)) \
		: (bin->first + SMALL(request));
	BT(chunk) = request;
	*(size_t *)(bin->first - (2 * sizeof(size_t))) = request;
	BT(chunk) = bin->freespace;
	return (chunk);
}
