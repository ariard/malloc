/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 23:12:25 by ariard            #+#    #+#             */
/*   Updated: 2018/01/30 23:53:41 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h" 

void		signal_handler(int sig)
{
	(void)sig;
	write(1, "calling thr : ", 14);
	print_value(1, (unsigned long)pthread_self());
	write(1, "\n", 1);
	raise(6);
}
