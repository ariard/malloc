/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_merge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 19:33:14 by ariard            #+#    #+#             */
/*   Updated: 2018/01/30 18:33:08 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void	clean_chunk(t_chunk *tmp)
{
	size_t		size;

	if (tmp->next && (tmp->next)->prev)
		(tmp->next)->prev = tmp->prev;
	if (tmp->prev && (tmp->prev)->next)
		(tmp->prev)->next = tmp->next;
	tmp->next = NULL;
	tmp->prev = NULL;
	size = BT(tmp) & ~(1 << 0);
//	print_value(3, size);
//	write(3, "\n", 1);
//	print_addr(3, (unsigned long)tmp);
//	write(3, "\n", 1);
//	print_addr(3, (unsigned long)LSUM_ADDR((void *)tmp, size));
//	write(3, "\n", 1);
	SUM(tmp) = 0;
//	write(3, "cm - flag 3\n", 12);
	LSUM((void *)tmp, size) = 0;
//	write(3, "cm - flag 4\n", 12);
}

void		*chunk_merge(t_bin *bin, 
		t_chunk *chunk, size_t forward, size_t backward, char a)
{
	t_chunk		*tmp;
	size_t		new_size;
	size_t		s_bin;

	new_size = forward + backward;
	tmp = chunk;
	s_bin = (a == 0) ? g_cfg.tiny_area : g_cfg.small_area;
//	write(3, "max of bin :", 12);
//	print_value(3, s_bin);
//	write(3, "\n", 1);
//	write(3, "bin : ", 6);
//	print_addr(3, (unsigned long)bin);
//	write(3, "\n", 1);
//	write(3, "bin end : ", 10);
//	print_addr(3, (unsigned long)(char *)bin + s_bin);
//	write(3, "\n", 1);
//	write(3, "forward :", 9);
//	print_value(3, forward);
//	write(3, "\n", 1);
	while (forward)
	{
		clean_chunk(tmp);
		if ((forward -= (BT(tmp) & ~(1 << 0))) == 0)
			break;
		tmp = ((void *)tmp + (BT(tmp) & ~(1 << 0)));
		bin->nb--;
	}
	tmp = chunk;
	while (backward)
	{
		clean_chunk(tmp);
		if ((backward -= BT(tmp) & ~(1 << 0)) == 0)
			break;
		tmp = ((void *)tmp - (LT_PREV((void *)tmp) & ~(1 << 0)));
		bin->nb--;
	}
	bin->nb++;
	chunk_set(new_size, tmp);
	return (tmp);
}
