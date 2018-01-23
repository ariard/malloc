/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_verify.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 18:40:08 by ariard            #+#    #+#             */
/*   Updated: 2018/01/23 20:16:19 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

char		chunk_verify(void *ptr)
{
	size_t	size;
	size_t	e_size;

	write(3, "verify\n", 7);
	size = BT(ptr) & ~(1 << 0);
	write(3, "flag [A]\n", 10);
	if (!size)
		return (0);
	write(3, "flag [B]\n", 9);
	if (!((char *)ptr + size))
		return (0);
	e_size = *(size_t *)((char *)ptr + size - sizeof(size_t));
	write(3, "flag [D]\n", 9);
	if (!e_size)
		return (0);
	write(3, "flag [E]\n", 9);
	if (e_size != size)
		return (0);
	return (1);
}
