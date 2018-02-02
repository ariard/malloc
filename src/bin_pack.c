/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pack_bin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 23:19:14 by ariard            #+#    #+#             */
/*   Updated: 2018/02/02 19:48:24 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*bin_pack(t_area *ar, t_bin *bin, size_t req)
{
	t_chunk	*cand;
	t_chunk	*tmp;
	size_t	size;
	size_t	a_req;
	
	cand = NULL;
//	pthread_mutex_lock(&debug);
//	write(3, "bp - flag A : ", 14);
//	print_value(3, (unsigned long)pthread_self());
//	write(3, "\n", 1);
//	pthread_mutex_unlock(&debug);
	if (req <= g_cfg.limit_small)
	{
		a_req = (req <= g_cfg.limit_tiny) ? align(req, 16) : align(req, 512);
		a_req = (a_req < 48) ? 48 : a_req;
		tmp = ((int)(bin->freespace - a_req) < 0) ? NULL : bin->first;
		size = bin->freespace;
		while (tmp)
		{
			cand = (BT(tmp) <= size && BT(tmp) >= a_req) ? tmp : cand;
			size = (BT(tmp) <= size && BT(tmp) >= a_req) ? BT(tmp) : size;
			tmp = tmp->next;
		}
//		pthread_mutex_lock(&debug);
//		write(3, "bp - flag B : ", 14);
//		print_value(3, (unsigned long)pthread_self());
//		write(3, "\n ptr : ", 8);
//		print_addr(3, (unsigned long)(bin->freespace));
//		write(3, "\n", 1);
//		pthread_mutex_unlock(&debug);
		cand = (!cand && bin->freespace && (int)(bin->freespace - a_req)) 
			? chunk_coalesce(ar, bin->first, a_req, 0) : cand;
//		pthread_mutex_lock(&debug);
//		write(3, "bp - flag C : ", 14);
//		print_value(3, (unsigned long)pthread_self());
//		write(3, "\n", 1);
//		pthread_mutex_unlock(&debug);
		cand = (cand) ? chunk_init(bin, cand, a_req) : NULL;
	}
	else if (bin->freespace > req)
	{
		bin->freespace -= req;
		cand = bin->first;
	}
//	pthread_mutex_lock(&debug);
//	write(3, "bp - flag D : ", 14);
//	print_value(3, (unsigned long)pthread_self());
//	write(3, "\n", 1);
//	pthread_mutex_unlock(&debug);
	return ((void *)cand);
}
