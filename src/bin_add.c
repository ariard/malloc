/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_bin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 23:06:56 by ariard            #+#    #+#             */
/*   Updated: 2017/03/12 17:53:25 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_bin	*bin_add(t_config *config, size_t request)
{
	t_bin		*bin;
	int		size;

	bin = NULL;
	if (request < config->limit_tiny)
		size = config->tiny_area;
	else if (request < config->limit_small)
		size = config->small_area;	
	else
		size = request;
	DBG(GREEN "request request %zu\n" RESET, request); 
	DBG(GREEN "page request %d\n" RESET, size);
	bin = mmap(0, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE,
		-1, 0);
	bin_init(bin, size);
	return (bin);
}
