/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 23:13:19 by ariard            #+#    #+#             */
/*   Updated: 2018/01/30 21:38:26 by ariard           ###   ########.fr       */
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
	write(3, "r - flag A\n", 11);
	if (!size && ptr && (new = malloc(size)))
		free(ptr);
	if (size && !ptr)
		new = malloc(size);
	write(3, "r - flag B\n", 11);
	if (size && ptr && chunk_check(ar, ptr)) 
		new = (g_cfg.error) ? chunk_error(ptr, 1) : NULL;
	else if (size && ptr)
	{
		write(3, "r - flag C\n", 11);
		new = chunk_coalesce(ar, ptr, size, 1);
		if (!new)
		{
			write(3, "r - flag E\n", 11);
			//size req + actual size
			new = malloc(size + (BT(ptr) & ~(1 << 0)));
			ft_memcpy(new, ptr, ((BT(ptr) & ~(1 << 0))
				- 2 * sizeof(int) - 2 * sizeof(char)));
			free(ptr); 
		}
	}
	thread_unset2(ar);
	write(3, "r - flag F\n", 11);
	return (new);
}
