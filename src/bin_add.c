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

t_bin	*bin_add(t_config *config, size_t size)
{
	t_bin	*bin;
	int		nb;

	bin = NULL;
	if (size < config->limit_tiny)
		nb = config->tiny_area;
	else if (size < config->limit_small)
		nb = config->small_area;	
	else
		nb = size;
	DBG(GREEN "size request %zu\n" RESET, size); 
	DBG(GREEN "page request %d\n" RESET, nb);
	bin = mmap(0, nb, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE,
		-1, 0);
	bin_init(bin, size);
	return (bin);
}
