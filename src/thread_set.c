/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 19:17:14 by ariard            #+#    #+#             */
/*   Updated: 2018/01/20 00:10:09 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_area		*thread_set(void)
{
	void	*value;
	int		i;

	i = -1;
	if (!(value = pthread_getspecific(g_cfg.key)))
	{
		while (++i < 4 && pthread_mutex_trylock(&g_cfg.areas[i].mutex))
			;
		if (i == 4)
		{
			i = rand() % 4;
			pthread_mutex_lock(&g_cfg.areas[i].mutex);
		}
		pthread_setspecific(g_cfg.key, (void *)&g_cfg.areas[i]);
		return (&g_cfg.areas[i]);
	}
	pthread_mutex_lock(&((t_area *)value)->mutex);
	return (value);
}
