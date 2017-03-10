/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 20:07:42 by ariard            #+#    #+#             */
/*   Updated: 2017/03/10 20:13:12 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		malloc_init(t_config *config)
{
	config->page_size = getpagesize;
	config->tiny_area = config->page_size / 4;
	config->small_area = config->page_size;
	config->limit_tiny = config->tiny_area - 1;
	config->limit_small = config->small_area - 1;
	return ;
}
