/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 23:24:04 by ariard            #+#    #+#             */
/*   Updated: 2017/03/12 16:18:03 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		bin_init(t_bin *bin, size_t size)
{
	bin->next = NULL;
	bin->first_chunk = NULL;
	bin->size = size;
	bin->freespace = size;
}
