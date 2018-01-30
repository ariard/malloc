/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 19:17:14 by ariard            #+#    #+#             */
/*   Updated: 2018/01/31 00:29:10 by ariard           ###   ########.fr       */
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
			write(3, "ts - flag A : ", 14);
			print_value(3, (unsigned long)pthread_self());
			write(3, "\n", 1);
			pthread_mutex_lock(&g_cfg.areas[i].mutex);
		}
		pthread_mutex_lock(&debug);
		write(3, "taking : ", 9);
		print_addr(3, (unsigned long)&g_cfg.areas[i].mutex);
		write(3, " by ", 4);
		print_value(3, (unsigned long)pthread_self());
		write(3, "\n", 1);
		pthread_mutex_unlock(&debug);
		g_cfg.areas[i].reentrancy = "1";
		pthread_setspecific(g_cfg.key, (void *)&g_cfg.areas[i]);
		return (&g_cfg.areas[i]);
	}
	if (!ft_strncmp(((t_area *)value)->reentrancy, "0", 1))
	{
		write(3, "ts - flag B : ", 14);
		print_value(3, (unsigned long)pthread_self());
		write(3, "\n", 1);
		pthread_mutex_lock(&((t_area *)value)->mutex); 
		pthread_mutex_lock(&debug);
		write(3, "taking : ", 9);
		print_addr(3, (unsigned long)&((t_area *)value)->mutex);
		write(3, " by ", 4);
		print_value(3, (unsigned long)pthread_self());
		write(3, "\n", 1);
		pthread_mutex_unlock(&debug);
	}
	if (!ft_strncmp(((t_area *)value)->reentrancy, "0", 1))
		(((t_area *)value)->reentrancy) = "1";
	return (value);
}
