/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 23:24:04 by ariard            #+#    #+#             */
/*   Updated: 2017/03/11 23:44:42 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		bin_init(t_bin *bin)
{
	bin->next = NULL;
	bin->first = NULL;
	bin->size = 0;
	bin->status = FREED;
}	
