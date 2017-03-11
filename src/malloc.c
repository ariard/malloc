/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 20:01:04 by ariard            #+#    #+#             */
/*   Updated: 2017/03/10 20:14:41 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <stdio.h>

void		*malloc(size_t size)
{
	static t_config		config;
	t_bin			*temp;
	void			*freespace;

	if (!config.page_size)
		malloc_init(&config);
	temp = first_bin;
	freesapce = NULL;
	while(temp)
	{
		if (check_bin(temp, size))
			freespace = pack_bin(temp, size);
		if (freespace)
			return (freespace);
		temp = temp->next;
	}		
	return (NULL);
}
