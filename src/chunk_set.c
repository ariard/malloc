/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 22:04:59 by ariard            #+#    #+#             */
/*   Updated: 2018/01/30 20:15:17 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
 
void		chunk_set(size_t a_req, t_chunk *chunk)
{
	size_t	s_clean;

	s_clean = a_req & ~(1 << 0);
	BT(chunk) = a_req;
	SUM(chunk) = checksum(BT(chunk));
	LT((void *)chunk, s_clean) = a_req;
	LSUM((void *)chunk, s_clean) = checksum(BT(chunk));
//	write(3, "size : ", 7);
//	print_value(3, s_clean);
//	write(3, "\n", 1);
//	write(3, "addr chunk : ", 13);
//	print_addr(3, (unsigned long)chunk);
//	write(3, "\n", 1);
//	write(3, "addr lsum : ", 12);
//	print_addr(3, (unsigned long)LSUM_ADDR((void *)chunk, s_clean));
//	write(3, "\n", 1);
//	write(3, "addr lt : ", 12);
//	print_addr(3, (unsigned long)LT_ADDR((void *)chunk, s_clean));
//	write(3, "\n", 1);
}
