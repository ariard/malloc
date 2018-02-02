/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 19:17:14 by ariard            #+#    #+#             */
/*   Updated: 2018/02/02 20:19:23 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_area		*thread_set(void)
{
	void	*value;
	int		i;

	i = -1;
//	pthread_mutex_lock(&debug);
//	write(3, "ts - flag A : ", 14);
//	print_value(3, (unsigned long)pthread_self());
//	write(3, "\n", 1);
//	pthread_mutex_unlock(&debug);
	if (!(value = pthread_getspecific(g_cfg.key)))
	{
		while (++i < 4 && pthread_rwlock_trywrlock(&g_cfg.areas[i].rwlock))
			;
		if (i == 4)
		{
			i = rand() % 4;
			pthread_rwlock_wrlock(&g_cfg.areas[i].rwlock);
		}
		g_cfg.areas[i].reentrancy = "1";
		pthread_setspecific(g_cfg.key, (void *)&g_cfg.areas[i]);
		return (&g_cfg.areas[i]);
	}
	pthread_rwlock_rdlock(&((t_area *)value)->rwlock);
	if (!ft_strncmp(((t_area *)value)->reentrancy, "0", 1))
	{
		pthread_rwlock_unlock(&((t_area *)value)->rwlock);
		pthread_rwlock_wrlock(&((t_area *)value)->rwlock); 
		(((t_area *)value)->reentrancy) = "1";
	}
	else
		pthread_rwlock_unlock(&((t_area *)value)->rwlock);

//	write(3, "ts - flag C : ", 14);
//	print_value(3, (unsigned long)pthread_self());
//	write(3, "\n", 1);
	return (value);
}
