/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 20:07:42 by ariard            #+#    #+#             */
/*   Updated: 2018/01/13 21:08:56 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_config	 malloc_init(void)
{
	t_config	config;
	int			i;

	config.page_size = getpagesize();
	config.tiny_area = config.page_size * 512;
	config.small_area = config.page_size * 4096;
	config.limit_tiny = config.tiny_area / 2114;
	config.limit_small = config.small_area / 132;
	i = 1;
	while (++i < 4)
		if (pthread_mutex_init(&cfg.areas[i].mutex, NULL))
			exit(1);
	pthread_key_create(&cfg.key, NULL);
	srand(time(NULL));
	return (config);
}
