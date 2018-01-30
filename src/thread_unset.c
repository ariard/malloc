/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_unset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 20:49:39 by ariard            #+#    #+#             */
/*   Updated: 2018/01/31 00:23:12 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		thread_unset2(t_area *ar)
{
	if (!ft_strncmp(ar->reentrancy, "1", 1))
	{
		pthread_mutex_unlock(&ar->mutex);
		ar->reentrancy = "0";
		pthread_mutex_lock(&debug);
		write(3, "giving : ", 9);
		print_addr(3, (unsigned long)&ar->mutex);
		write(3, " by ", 4);
		print_value(3, (unsigned long)pthread_self());
		write(3, "\n", 1);
		pthread_mutex_unlock(&debug);
	}
}
