/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_unset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 20:49:39 by ariard            #+#    #+#             */
/*   Updated: 2018/01/24 19:03:55 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		thread_unset2(t_area *ar)
{
	if (!ft_strncmp(ar->reentrancy, "b", 1))
		pthread_mutex_unlock(&ar->mutex);
	if (!ft_strncmp(ar->reentrancy, "b", 1))
		ar->reentrancy = "a";
}
