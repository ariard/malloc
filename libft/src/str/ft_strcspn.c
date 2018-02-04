/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 15:02:09 by ariard            #+#    #+#             */
/*   Updated: 2018/02/04 15:02:41 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcspn(char *s, const char *delim)
{
	char	*str;

	str = s;
	while (*str)
	{
		if (ft_strchr(delim, *str))
			return (str - s);
		else
			str++;
	}
	return (str - s);
}
