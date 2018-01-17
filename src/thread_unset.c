/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_unset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 20:49:39 by ariard            #+#    #+#             */
/*   Updated: 2018/01/18 00:17:58 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		*thread_unset(pthread_mutex_t *mutex, void *ptr)
{
	DBG("thread %d unlock mutex %p\n", (int)pthread_self(), mutex);
	pthread_mutex_unlock(mutex);
	return (ptr);
}
