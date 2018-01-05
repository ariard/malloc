/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pack_bin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 23:19:14 by ariard            #+#    #+#             */
/*   Updated: 2018/01/05 23:53:10 by ariard           ###   ########.fr       */
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
	struct s_chunk	*best;
	struct s_chunk	*tmp;
	size_t			size;

	if ((request < config->limit_tiny && bin->freespace == config->tiny_area) \
		|| (request < config->limit_small && bin->freespace == config->small_area))
	{
		DBG(GREEN "first chunk of bin\n" RESET);
		return (chunk_init(config, bin, request));
	}
	tmp = bin->first;
	size = bin->freespace;
	while (tmp)
	{
		if (*(size_t *)((void *)tmp - 1) < size)
		{
			best = tmp;
			size = *(size_t *)((void *)tmp - 1);
		}
		tmp = tmp->next;
	}
	if (best->prev)
		(best->prev)->next = best->next;
	if (best->next)
		(best->next)->prev = best->prev;
//	return (chunk_init(config, best, request));
	return (chunk_init(config, bin, request));
}

// not special case but split vs stock
//
// 1. clean stock :
// 		bd tags then listptr on next, bd on it
// 2 list :
// 		cross and if fit same technics than 1
//
// 	policy "filler manage next free buddy"
