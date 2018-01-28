/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   area_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 22:29:25 by ariard            #+#    #+#             */
/*   Updated: 2018/01/26 23:58:42 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		area_print(t_bin *bin, int a)
{
	char	*ar;

	ar = (a == 0) ? "TINY" : "SMALL";
	ar = (a == 2) ? "LARGE" : ar;
	ft_dprintf(2, "[%s] : %p\n", ar, bin);
}
