/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pack_bin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 23:19:14 by ariard            #+#    #+#             */
/*   Updated: 2017/03/11 23:46:04 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

/*
** Pack the request in a new chunk from the bin
*/

void	*bin_pack(t_bin *bin, size_t size)
{
	t_chunk		*temp;
	t_chunk		*prev;
	
	DBG(GREEN "BIN_PACK\n" RESET);
	bin->size -= size;
	if (!bin->first_chunk)
		return ((bin->first_chunk = chunk_init(freespace, size, NULL))->data);
	temp = bin->first_chunk;
	while (temp)
	{
		if (chunk_check(temp, size))
			return (temp->data);
		prev = temp;
		if (!(temp = temp->next))
		{
			temp = chunk_init(freespace, size, temp);
			prev->next = temp;
		}
	}
	return (NULL);
}
