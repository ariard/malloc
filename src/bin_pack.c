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
	void		*freespace;
	t_chunk		*temp;
	
	bin->size -= size;
	freespace = bin->data;
	if (!bin->first_chunk)
		return ((bin->first_chunk = chunk_init(freespace, size, NULL))->data);
	temp = bin->first_chunk;
	while (temp->next)
	{
		if (chunk_check(temp, size))
			return (temp->data);
		freespace += (sizeof(t_chunk) + temp->size);
		temp = temp->next;
	}
	temp->next = chunk_init(freespace, size, temp);
	return ((temp->next)->data);
}
