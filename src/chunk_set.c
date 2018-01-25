/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 22:04:59 by ariard            #+#    #+#             */
/*   Updated: 2018/01/25 00:34:52 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
 
void		chunk_set(size_t a_req, t_chunk *chunk)
{
	BT(chunk) = a_req;
	SUM(chunk) = checksum(BT(chunk));
	LT((void *)chunk, a_req) = a_req;
	LSUM((void *)chunk, a_req) = checksum(BT(chunk));
}
