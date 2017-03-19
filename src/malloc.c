/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 20:01:04 by ariard            #+#    #+#             */
/*   Updated: 2017/03/12 17:19:50 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <stdio.h>

t_bin		*first_bin = NULL;

void		*malloc(size_t size)
{
	static t_config		config;
	t_bin			*temp;
	void			*freespace;

	DBG(GREEN "\nBEGIN MALLOC\n" RESET);
	if (!config.page_size)
		malloc_init(&config);
	if (!first_bin)
		first_bin = bin_add(&config, size);
	temp = first_bin;
	freespace = NULL;
	while (temp->next)
	{
		if (bin_check(temp, size))
			return (freespace = bin_pack(temp, size));
		temp = temp->next;
	}
	temp->next = bin_add(&config, size);	
	return ((freespace = bin_pack(temp->next, size)));
}
