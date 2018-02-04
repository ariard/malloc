/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 19:06:27 by ariard            #+#    #+#             */
/*   Updated: 2018/02/04 15:38:07 by ariard           ###   ########.fr       */
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
	write(2, "[", 1);
	print_addr(2, (unsigned long)ptr);
	write(2, "] ", 2);
	write(2, error[e], ft_strlen(error[e]));
	write(2, " - abort\n", 9);
	raise(6);
	return (NULL);
}
