/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 19:06:27 by ariard            #+#    #+#             */
/*   Updated: 2018/01/26 18:33:18 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*chunk_error(void *ptr, int e)
{
	char	*error[4]; 

	error[0] = "object freed was not allocated";
	error[1] = "object realloced was not allocated";
	error[2] = "memory corruption";
	error[3] = "out of memory";
	ft_dprintf(2, "[%p] %s - abort", ptr, error[e]);
	raise(6);
	return (NULL);
}
