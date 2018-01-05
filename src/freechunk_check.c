/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freechunk_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 22:35:21 by ariard            #+#    #+#             */
/*   Updated: 2018/01/05 22:40:02 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

char	freechunk_check(void *chunk, size_t *size)
{
	size_t	ct;

	ct = *(size_t *)(chunk - 1);	
	if (ct < size)
		return(*size = ct);
	return (0);

}
