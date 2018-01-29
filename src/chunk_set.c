/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 22:04:59 by ariard            #+#    #+#             */
/*   Updated: 2018/01/30 00:16:00 by ariard           ###   ########.fr       */
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
}
