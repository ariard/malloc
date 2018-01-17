/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 19:17:14 by ariard            #+#    #+#             */
/*   Updated: 2018/01/18 00:17:40 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_area		*thread_set(void)
{
	void	*value;
	int		i;

	i = -1;
	if (!(value = pthread_getspecific(cfg.key)))
	{
		while (++i < 4 && pthread_mutex_trylock(&cfg.areas[i].mutex)) 
			;
		if (i == 4)
		{
			i = rand() % 4;
			if (pthread_mutex_lock(&cfg.areas[i].mutex))
				exit(1);
		}
		pthread_setspecific(cfg.key, (void *)&cfg.areas[i]);
		//DBG("thread %d has area %p\n", (int)pthread_self(), (void *)&cfg.areas[i]);
		return (&cfg.areas[i]);
	}
	//DBG("thread %d gonna wait for mutex %p\n", (int)pthread_self(), (void *)&cfg.areas[i]);
	pthread_mutex_lock(value);
	//DBG("thread %d has its mutex %p\n", (int)pthread_self(), (void *)&cfg.areas[i]);
	return (value);
}
