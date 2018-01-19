/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_unset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 20:49:39 by ariard            #+#    #+#             */
/*   Updated: 2018/01/19 19:08:02 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		*thread_unset(pthread_mutex_t *mutex, void *ptr)
{
	pthread_mutex_unlock(mutex);
	return (ptr);
}

void		thread_unset2(pthread_mutex_t *mutex)
{
	pthread_mutex_unlock(mutex);
}