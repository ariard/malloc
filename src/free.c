/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 21:17:14 by ariard            #+#    #+#             */
/*   Updated: 2018/01/06 23:02:51 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void			free(void *ptr)
{
	t_bin 	*temp;
	t_bin	*prev;
	t_chunk	*list;

	DBG(GREEN "FREE\n" RESET);
	temp = first_bin;
	while (ptr && temp)
	{
		//DBG("[addr ptr] %p\n [addr min] %p\n [addr max] %p\n", ptr, temp, (char *)temp + 2097152);
		DBG(GREEN "in free test\n" RESET);
		if (((char *)temp - (char *)ptr) < 0 
			&& ((char *)temp + 2097152 - (char *)ptr) > 0)
		{
			DBG("success");
			list = temp->first;
			while (list->next && (list = list->next));
			list->next = ptr;
			temp->freespace += TINY(*(size_t *)(ptr - sizeof(size_t)));
			if (temp->freespace == 2097152)
			{
				prev->next = temp->next;
				munmap(temp, 2097152);
				break;
			}
		}
		prev = temp;
		temp = temp->next;
	}
}
