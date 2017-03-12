/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 20:01:04 by ariard            #+#    #+#             */
/*   Updated: 2017/03/12 01:34:35 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <stdio.h>

t_bin		*first_bin = NULL;

void		*malloc(size_t size)
{
	static t_config		config;
	t_bin				*temp;
	void				*freespace;

	dprintf(3, "in malloc\n");
	if (!config.page_size)
		malloc_init(&config);
	dprintf(3, "after malloc init\n");
	if (!first_bin)
		first_bin =	bin_add(&config, size);
	dprintf(3, "after bin add\n");
	temp = first_bin;
	freespace = NULL;
	while (temp)
	{
		if (bin_check(temp, size))
			freespace = bin_pack(temp, size);
		if (freespace)
			return (freespace);
		temp = temp->next;
	}		
	return (NULL);
}
