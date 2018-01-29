/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 20:01:04 by ariard            #+#    #+#             */
/*   Updated: 2018/01/26 22:16:11 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_config		g_cfg = { .once = PTHREAD_ONCE_INIT };

void			*malloc(size_t request)
{
	t_bin				*temp;
	void				*chunk;
	t_area				*ar;

	//DBG(GREEN "MALLOC\n" RESET);
	pthread_once(&g_cfg.once, malloc_init);
	ar = thread_set();
	bin_check(ar);
	ar->list[0] = (!ar->list[0] && request <= g_cfg.limit_tiny)
		? bin_add(request) : ar->list[0];
	ar->list[1] = (!ar->list[1] && request <= g_cfg.limit_small \
		&& request > g_cfg.limit_tiny) ? bin_add(request) : ar->list[1];
	ar->list[2] = (!ar->list[2] && request > g_cfg.limit_small)
		? bin_add(request) : ar->list[2];
	temp = (request > g_cfg.limit_tiny) ? ar->list[1] : ar->list[0];
	temp = (request > g_cfg.limit_small) ? ar->list[2] : temp;
	while (temp)
	{
		if ((chunk = bin_pack(ar, temp, request)))
			break;
		temp->next = (!temp->next) ? bin_add(request) : temp->next;
		temp = temp->next;
	}
	logmem(chunk, 0, ar);
	thread_unset2(ar);
	return (chunk);
}
