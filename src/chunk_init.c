/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 18:49:55 by ariard            #+#    #+#             */
/*   Updated: 2018/01/05 21:59:41 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

//t_chunk	*chunk_init(void *freespace, size_t size, t_chunk *previous)
//{
//	t_chunk	*new;
//
//	new = freespace;
//	new->next = NULL;		
//	new->previous = previous;
//	new->status = FULL;
//	new->size = size;
//	return (new);
//}	

void	*chunk_init(t_config *config, t_bin *bin, size_t request)
{
	void	*temp;

//	DBG(GREEN "CHUNCK_INIT\n" RESET);
//	DBG(GREEN "size of bin %lu\n" RESET, sizeof(t_bin));
//	DBG(GREEN "size of first %lu\n" RESET, sizeof(bin->first));
	temp = bin->first;
	if (request < config->limit_small)
		bin->first = (request < config->limit_tiny) ? (bin->first + TINY(request, bin->first)) \
			: (bin->first + SMALL(request, bin->first));
//	DBG(GREEN "new chunk is %p\n", temp);
//	DBG(GREEN "first %p\n", bin->first);
//	DBG(GREEN "diff %ld\n", bin->first - temp);
	*(size_t *)temp = request;
	*(size_t *)(bin->first - 1) = request;
	return (temp + 1);
}
