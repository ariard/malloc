/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 22:04:59 by ariard            #+#    #+#             */
/*   Updated: 2018/01/24 22:08:00 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
 
void		set_chunk(size_t a_req, t_chunk *chunk)
{
	BT(chunk) = SET_BUSY(a_req);
	SUM(chunk) = checksum(BT(chunk));
	LT((void *)chunk, a_req) = SET_BUSY(a_req);
	LSUM((void *)chunk) = checksum(BT(chunk));
}
