/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 19:17:14 by ariard            #+#    #+#             */
/*   Updated: 2018/01/26 21:49:21 by ariard           ###   ########.fr       */
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
		g_cfg.areas[i].reentrancy = "1";
		pthread_setspecific(g_cfg.key, (void *)&g_cfg.areas[i]);
		return (&g_cfg.areas[i]);
	}
	if (!ft_strncmp(((t_area *)value)->reentrancy, "0", 1))
		pthread_mutex_lock(&((t_area *)value)->mutex); 
	if (!ft_strncmp(((t_area *)value)->reentrancy, "0", 1))
		(((t_area *)value)->reentrancy) = "1";
	return (value);
}
