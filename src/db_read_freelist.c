/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_read_freelist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 20:36:57 by ariard            #+#    #+#             */
/*   Updated: 2018/01/06 23:17:25 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "malloc.h"

void	read_freelist(void)
{
	t_chunk	*tmp;
	int		i;

	tmp = first_bin->first;
	i = 0;
	printf("\n");
	while (tmp)
	{
		printf("[chunk %d] size %zu %p\n", i++, *(size_t *)((void *)tmp - sizeof(size_t)), tmp);
		tmp = tmp->next;

		// hors bin, to correct in chunk_init
	}
	printf("_ _\n");
}
