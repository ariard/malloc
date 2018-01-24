/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checksum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 22:16:32 by ariard            #+#    #+#             */
/*   Updated: 2018/01/24 22:23:26 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

char		checksum(size_t size)
{
	unsigned int	count;

	count = 0;
	while (size)
	{
		count += (size & 1);
		size >>= 1;
	}
	return ((char)count);
}
