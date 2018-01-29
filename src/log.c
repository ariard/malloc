/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 17:35:13 by ariard            #+#    #+#             */
/*   Updated: 2018/01/30 00:13:17 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	logmem(void *ptr, char from, t_area *ar)
{
	static int	file;	
	char		name[100 + 1];
	char		*pid;

	if (!g_cfg.log)
		return;
	if (!ft_strncmp(ar->reentrancy, "2", 1))
		return;	
	ar->reentrancy = "2";
	if (!file)	
	{
		ft_bzero(name, 100);
		ft_strcpy(name, "/tmp/.tmp-malloc-log-");
		pid = ft_itoa((int)getpid());
		ft_strcat(name, pid);
		file = open(name, O_CREAT | O_WRONLY, 0644);
		free(pid);
	}
	if (ptr && file)
		ft_dprintf(file, "[%lu] - %s - %p size : %lu\n", (long)pthread_self(),
			(from == 0) ? "malloc" : "free", ptr, BT(ptr));
	ar->reentrancy = "1";
}
