/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pack_bin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 23:19:14 by ariard            #+#    #+#             */
/*   Updated: 2017/03/11 23:46:04 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"


void	*bin_pack(t_bin *bin, size_t req, t_cfg *cfg)
{
	char	*temp;	
	char	*prev;

	temp = bin->free_list;
	prev = NULL;
	while (temp)
	{
		if (chunk_check(temp, request))
			return (chunk_pack(prev, temp, request));
		prev = temp;
		temp = temp->next;			
	}
	return (NULL)
}
