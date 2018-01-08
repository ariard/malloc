/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 20:07:42 by ariard            #+#    #+#             */
/*   Updated: 2018/01/08 22:59:03 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_config	 malloc_init(void)
{
	t_config	config;
	config.page_size = getpagesize();
	config.tiny_area = config.page_size * 512;
	config.small_area = config.page_size * 4096;
	config.limit_tiny = config.tiny_area / 2114;
	config.limit_small = config.small_area / 132;
	return (config);
}
