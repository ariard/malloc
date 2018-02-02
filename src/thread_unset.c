/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_unset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 20:49:39 by ariard            #+#    #+#             */
/*   Updated: 2018/02/02 19:57:08 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		thread_unset2(t_area *ar)
{
	if (!ft_strncmp(ar->reentrancy, "1", 1))
	{
//		write(3, "tu - flag A : ", 14);
//		print_value(3, (unsigned long)pthread_self());
//		write(3, "\n", 1);
		pthread_rwlock_unlock(&ar->rwlock);
		ar->reentrancy = "0";
	}
}
