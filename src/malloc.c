/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 20:01:04 by ariard            #+#    #+#             */
/*   Updated: 2018/01/05 20:58:05 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <stdio.h>

t_bin		*first_bin = NULL;

void	*malloc(size_t request)
{
	static t_config		config;
	t_bin				*temp;
	
	DBG(GREEN "MALLOC\n" RESET);
	if (!config.page_size)
		malloc_init(&config);
	if (!first_bin)
		first_bin = bin_add(&config, request);
	temp = first_bin;
	while (temp)
	{
		if (temp->freespace > request)
			return (bin_pack(&config, temp, request));
		if (!temp->next)
			temp->next = bin_add(&config, request);
		temp = temp->next;
	}
	return (NULL);
}
