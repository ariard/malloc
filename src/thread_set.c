/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 19:17:14 by ariard            #+#    #+#             */
/*   Updated: 2018/01/13 23:54:10 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_area		*thread_set(void)
{
	void	*value;
	int		i;

	i = -1;
	DBG("addr %p\n", cfg.key);
	DBG("thread set A\n");
	if (!(value = pthread_getspecific(*cfg.key)))
	{
		DBG("thread set C\n");
		while (++i < 4 && pthread_mutex_trylock(&cfg.areas[i].mutex)) 
			;
		if (i == 4)
		{
			i = rand() % 4;
			if (pthread_mutex_lock(&cfg.areas[i].mutex))
				exit(1);
		}
		pthread_setspecific(*cfg.key, (void *)&cfg.areas[i]);
		return (&cfg.areas[i]);
	}
	DBG("thread set D\n");
	if (value)
		DBG("value exits : %p", value);
	return (value);
}
