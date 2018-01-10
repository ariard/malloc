/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 20:01:04 by ariard            #+#    #+#             */
/*   Updated: 2018/01/10 19:22:51 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <sys/time.h>

t_area	area = { {NULL, NULL, NULL}, {0, 0, 0, 0, 0} };

void			*malloc(size_t request)
{
	t_bin				*temp;
	void				*chunk;
	
	DBG(GREEN "MALLOC\n" RESET);
	area.cfg = (area.cfg.page_size == 0) ? malloc_init() : area.cfg;
	area.list[0] = (!area.list[0] && request <= area.cfg.limit_tiny)
		? bin_add(request) : area.list[0];
	area.list[1] = (!area.list[1] && request <= area.cfg.limit_small \
		&& request > area.cfg.limit_tiny) ? bin_add(request) : area.list[1];
	area.list[2] = (!area.list[2] && request > area.cfg.limit_small) 
		? bin_add(request) : area.list[2];
	temp = (request > area.cfg.limit_tiny) ? area.list[1] : area.list[0];
	temp = (request > area.cfg.limit_small) ? area.list[2] : temp;
	while (temp)
	{
		if (temp->freespace > request)
			if ((chunk = bin_pack(temp, request)))
				return (chunk);
		temp->next = (!temp->next) ? bin_add(request) : temp->next;
		temp = temp->next;
	}
	return (NULL);
}
