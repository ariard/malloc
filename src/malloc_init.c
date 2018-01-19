/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 20:07:42 by ariard            #+#    #+#             */
/*   Updated: 2018/01/19 18:54:45 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		malloc_init(void)
{
	int						i;

	g_cfg.page_size = getpagesize();
	g_cfg.tiny_area = g_cfg.page_size * 512;
	g_cfg.small_area = g_cfg.page_size * 4096;
	g_cfg.limit_tiny = g_cfg.tiny_area / 2114;
	g_cfg.limit_small = g_cfg.small_area / 132;
	i = -1;
	while (++i < 4)
		pthread_mutex_init(&g_cfg.areas[i].mutex, NULL);
	pthread_key_create(&g_cfg.key, NULL);
	srand(time(NULL));
}
