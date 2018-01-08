/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_read_freelist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 20:36:57 by ariard            #+#    #+#             */
/*   Updated: 2018/01/08 17:34:17 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "malloc.h"

//void	read_freelist(void)
//{
//	t_bin	*bin;
//	t_chunk	*chunk;
//	int		i;
//	int		j;
//
//	bin = first_bin;
//	printf("\n");
//	j = 0;
//	while (bin)
//	{
//		chunk = bin->first;
//		i = 0;
//		printf("[BIN %d]\n", j++);
//		while (chunk)
//		{
//			printf("[chunk %d] size %zu %p\n", i++, *(size_t *)((void *)chunk - sizeof(size_t)), chunk);
//			chunk = chunk->next;
//		}
//		printf("\n");
//		bin = bin->next;
//	}
//}
