/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pack_bin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 23:19:14 by ariard            #+#    #+#             */
/*   Updated: 2018/01/05 21:58:31 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

//void	*bin_pack(t_bin *bin, size_t size)
//{
//	t_chunk		*temp;
//	t_chunk		*prev;
//	void		*freespace;
//	
//	freespace = NULL;
//	DBG(GREEN "BIN_PACK\n" RESET);
//	bin->size -= size;
//	if (!bin->first_chunk)
//		return ((bin->first_chunk = chunk_init(freespace, size, NULL))->data);
//	temp = bin->first_chunk;
//	while (temp)
//	{
//		if (chunk_check(temp, size))
//			return (temp->data);
//		prev = temp;
//		if (!(temp = temp->next))
//		{
//			temp = chunk_init(freespace, size, temp);
//			prev->next = temp;
//		}
//	}
//	return (NULL);
//}

void	*bin_pack(t_config *config, t_bin *bin, size_t request)
{
	bin->freespace -= request;
	return (chunk_init(config, bin, request));
}
