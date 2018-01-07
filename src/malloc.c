/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 20:01:04 by ariard            #+#    #+#             */
/*   Updated: 2018/01/07 20:24:49 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <sys/time.h>

t_area	area = { NULL, NULL, NULL, NULL };

void			*malloc(size_t request)
{
	t_config			config;
	t_bin				*temp;
	
	DBG(GREEN "MALLOC\n" RESET);
	area.cfg = (!area.cfg) ? malloc_init(&config) : area.cfg;
	area.tiny = (!area.tiny && request <= config.limit_tiny) ? bin_add(request) : area.tiny;
	area.small = (!area.small && request <= config.limit_small) ? bin_add(request) : area.small;
	area.large = (!area.large && request > config.limit_small) ? bin_add(request) : area.large;
	temp = (request > config.limit_tiny) ? area.small : area.tiny;
	temp = (request > config.limit_small) ? area.large : temp;
	while (temp)
	{
		if (temp->freespace > request)
			return (bin_pack(temp, request));
		temp->next = (!temp->next) ? bin_add(request) : temp->next;
		temp = temp->next;
	}
	return (NULL);
}
