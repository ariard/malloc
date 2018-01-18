/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 20:07:42 by ariard            #+#    #+#             */
/*   Updated: 2018/01/18 17:47:26 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	 malloc_init(void)
{
	int						i;

	cfg.page_size = getpagesize();
	cfg.tiny_area = cfg.page_size * 512;
	cfg.small_area = cfg.page_size * 4096;
	cfg.limit_tiny = cfg.tiny_area / 2114;
	cfg.limit_small = cfg.small_area / 132;
	i = -1;
	while (++i < 4)
		pthread_mutex_init(&cfg.areas[i].mutex, NULL);
	pthread_key_create(&cfg.key, NULL);
	srand(time(NULL));
}
