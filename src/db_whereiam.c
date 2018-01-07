/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_whereiam.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 19:10:58 by ariard            #+#    #+#             */
/*   Updated: 2018/01/07 19:14:35 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	whereiam(size_t request)
{
	if (request <= area.cfg->limit_tiny)
		DBG("TINY AREA\n")
	else if (request <= area.cfg->limit_small)
		DBG("SMALL AREA\n")
	else 
		DBG("LARGE AREA\n")
}
