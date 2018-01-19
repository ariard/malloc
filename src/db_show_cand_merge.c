/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_show_cand_merge.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 20:28:52 by ariard            #+#    #+#             */
/*   Updated: 2018/01/19 18:46:55 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		show_cand_merge(void *ptr, t_cand cand)
{
	ft_printf("cand : %p low : %p high : %p\n",
		ptr, ptr - cand.backward, ptr + cand.forward);
}
