/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 19:17:14 by ariard            #+#    #+#             */
/*   Updated: 2018/01/18 19:38:27 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

pthread_key_t	thrfd;

t_area		*thread_set(void)
{
	void	*value;
	int	i;

	i = -1;
	if (!(value = pthread_getspecific(cfg.key)))
	{
		while (++i < 4 && pthread_mutex_trylock(&cfg.areas[i].mutex)) 
			;
		if (i == 4)
		{
			i = rand() % 4;
			pthread_mutex_lock(&cfg.areas[i].mutex);
		}
		pthread_setspecific(cfg.key, (void *)&cfg.areas[i]);
		return (&cfg.areas[i]);
	}
	pthread_mutex_lock(&((t_area *)value)->mutex);
	return (value);
}
