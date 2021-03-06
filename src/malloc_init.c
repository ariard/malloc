/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 20:07:42 by ariard            #+#    #+#             */
/*   Updated: 2018/02/04 15:32:54 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void		wrapper_env(void)
{
	char	*s;

	s = getenv("MallocCheckHeapStart");
	g_cfg.start = (s) ? ft_atoi(s) : 0;
	s = getenv("MallocCheckHeapEach");
	g_cfg.check = (s) ? ft_atoi(s) : 0;
	s = getenv("MallocErrorAbort");
	g_cfg.error = (s) ? 1 : 0;
	s = getenv("MallocLogHistory");
	g_cfg.log = (s) ? 1 : 0;
}

void			malloc_init(void)
{
	int						i;

	g_cfg.page_size = getpagesize();
	g_cfg.tiny_area = g_cfg.page_size * 512;
	g_cfg.small_area = g_cfg.page_size * 4096;
	g_cfg.limit_tiny = g_cfg.tiny_area / 2114;
	g_cfg.limit_small = g_cfg.small_area / 132;
	i = -1;
	while (++i < 4)
	{
		g_cfg.areas[i].list[0] = NULL;
		g_cfg.areas[i].list[1] = NULL;
		g_cfg.areas[i].list[2] = NULL;
		pthread_rwlock_init(&g_cfg.areas[i].rwlock, NULL);
		g_cfg.areas[i].reentrancy = "0";
	}
	pthread_key_create(&g_cfg.key, NULL);
	srand(time(NULL));
	wrapper_env();
}
