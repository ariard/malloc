/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 23:13:19 by ariard            #+#    #+#             */
/*   Updated: 2018/01/26 18:32:38 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		*realloc(void *ptr, size_t size)
{
	void	*new;
	t_area	*ar;

	pthread_once(&g_cfg.once, malloc_init);
	ar = thread_set();
	new = NULL;
	if (!size && ptr && (new = malloc(size)))
		free(ptr);
	if (size && !ptr)
		new = malloc(size);
	if (size && ptr && chunk_check(ar, ptr)) 
		new = (getenv("MallocErrorAbort")) ? chunk_error(ptr, 1) : NULL;
	else if (size && ptr)
	{
		new = chunk_coalesce(ar, ptr, size, 1);
		if (!new)
		{
			new = malloc(size);
			ft_memcpy(new, ptr, (BT(ptr) & ~(1 << 0) 
				- 2 * sizeof(int) - 2 * sizeof(char)));
			free(ptr); 
		}
	}
	thread_unset2(ar);
	return (new);
}
