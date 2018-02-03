/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_search.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 18:59:18 by ariard            #+#    #+#             */
/*   Updated: 2018/02/02 20:48:35 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int		chunk_search(t_bins bs, void *chunk, size_t request, t_ctrl ctrl)
{
	void	*tmp;
	size_t	size;

//	write(3, "cs - flag A : ", 14);
//	write(3, "\n", 1);
//	print_addr(3, (unsigned long)chunk);
//	write(3, "\n", 1);
	size = (ctrl.pos < 0) ? LT_PREV(chunk) & ~(1 << 0) 
		: BT(chunk) & ~(1 << 0);
	tmp = (ctrl.pos < 0) ? chunk - size : chunk + size;
	if (FREE(*(size_t *)(tmp - sizeof(size_t))) && ctrl.sum < request)
	{
//		write(3, "cs - flag B : ", 14);
//		write(3, "\n", 1);
		if (BT(tmp) + ctrl.sum > request)
			return (BT(tmp) + ctrl.sum);
		if (bin_checkin(bs.bin, tmp, bs.a, ctrl.pos))
			return (chunk_search(bs, tmp, request,
				(t_ctrl){ ctrl.sum + BT(tmp), ctrl.pos }));
	}
	return (ctrl.sum);
}

// return size of last elem which called the func
