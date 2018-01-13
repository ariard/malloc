/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 20:01:04 by ariard            #+#    #+#             */
/*   Updated: 2018/01/13 23:12:01 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_config		cfg = { .once_control = PTHREAD_ONCE_INIT };

void			*malloc(size_t request)
{
	t_bin				*temp;
	void				*chunk;
	t_area				*ar;
	
	DBG(GREEN "MALLOC\n" RESET);
	cfg = (cfg.page_size == 0) ? malloc_init() : cfg;
	ar = thread_set();
	if (ar->list[0])
		DBG("list tiny bin alive\n"); 
	DBG("[A]\n");
	ar->list[0] = (!ar->list[0] && request <= cfg.limit_tiny)
		? bin_add(request) : ar->list[0];
	ar->list[1] = (!ar->list[1] && request <= cfg.limit_small \
		&& request > cfg.limit_tiny) ? bin_add(request) : ar->list[1];
	ar->list[2] = (!ar->list[2] && request > cfg.limit_small) 
		? bin_add(request) : ar->list[2];
	temp = (request > cfg.limit_tiny) ? ar->list[1] : ar->list[0];
	temp = (request > cfg.limit_small) ? ar->list[2] : temp;
	while (temp)
	{
		if (temp->freespace > request)
			if ((chunk = bin_pack(ar, temp, request)))
				return (thread_unset(&ar->mutex, chunk));
		temp->next = (!temp->next) ? bin_add(request) : temp->next;
		temp = temp->next;
	}
	return (thread_unset(&ar->mutex, NULL));
}
