/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_bin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 23:06:56 by ariard            #+#    #+#             */
/*   Updated: 2018/01/05 20:40:23 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_bin	*bin_add(t_config *config, size_t request)
{
	t_bin	*bin;
	int		size;

	DBG(GREEN "BIN_ADD\n" RESET);
	bin = NULL;
	if (request < config->limit_tiny)
		size = config->tiny_area;
	else if (request < config->limit_small)
		size = config->small_area;	
	else
		size = request;
//	DBG(GREEN "request request %zu\n" RESET, request); 
//	DBG(GREEN "page request %d\n" RESET, size);
	bin = mmap(0, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE,
		-1, 0);
	bin->next = NULL;
	bin->freespace = size;
	bin->first = bin + 1;
	return (bin);
}
