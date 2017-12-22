/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 22:59:20 by ariard            #+#    #+#             */
/*   Updated: 2017/03/12 15:46:27 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int		main(void)
{
	char	*str;

	str = malloc(100);
	strcpy(str, "hello world");
	printf("[%s]", str);
	return (0);
}
