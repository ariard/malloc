/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pack_bin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 23:19:14 by ariard            #+#    #+#             */
/*   Updated: 2018/01/25 00:38:08 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*bin_pack(t_area *ar, t_bin *bin, size_t req)
{
	t_chunk	*best;
	t_chunk	*tmp;
	size_t	size;
	size_t	a_req;

	write(3, "bin_pack\n", 9);
	tmp = bin->first;
	if ((int)(bin->freespace - (a_req = (req <= g_cfg.limit_tiny) 
		? align(req, 16) : align(req, 512))) < 0)
		tmp = NULL;
// 	however protect against corrupt in chunk init
//	a_req = (a_req < 48) ? 48 : a_req;
	best = NULL;
	size = bin->freespace;
	print_addr(bin->first);
	while (tmp)
	{
		write(3, "bp - flag A\n", 12);
		print_addr(tmp);
		best = (BT(tmp) <= size && BT(tmp) >= a_req) ? tmp : best;
		size = (BT(tmp) <= size && BT(tmp) >= a_req) ? BT(tmp) : size;
		tmp = tmp->next;
	}
	write(3, "bp - flag B\n", 12);
	if (best == NULL)
		write(4, "bp - flag C\n", 12);
	if (best == NULL)
		best = chunk_coalesce(ar, bin->first, a_req, 0);
	return ((best) ? chunk_init(bin, best, a_req) : NULL);
}
