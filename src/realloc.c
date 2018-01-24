/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 23:13:19 by ariard            #+#    #+#             */
/*   Updated: 2018/01/25 00:30:18 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		*realloc(void *ptr, size_t size)
{
	void	*new;
	t_area	*ar;

	write(3, "realloc\n", 9);
	pthread_once(&g_cfg.once, malloc_init);
	ar = thread_set();
	new = NULL;
	if (!size && ptr && (new = malloc(size)))
		free(ptr);
	if (size && !ptr)
		new = malloc(size);
	if (size && ptr && chunk_check(ar, ptr))
		new = chunk_error();
	else if (size && ptr)
	{
		new = chunk_coalesce(ar, ptr, size, 1);
		if (!new)
		{
			new = malloc(size);
			ft_memcpy(new, ptr, BT(ptr) - 2 * sizeof(size_t));
			free(ptr); 
		}
	}
	thread_unset2(ar);
	return (new);
}
