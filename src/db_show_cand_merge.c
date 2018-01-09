/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_show_cand_merge.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 20:28:52 by ariard            #+#    #+#             */
/*   Updated: 2018/01/09 20:38:45 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		show_cand_merge(void *ptr, t_cand cand)
{
	DBG("cand : %p low : %p high : %p\n", 
		ptr, ptr - cand.backward, ptr + cand.forward);
}
