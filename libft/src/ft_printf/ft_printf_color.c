/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:07:39 by jhalford          #+#    #+#             */
/*   Updated: 2018/02/04 15:05:14 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_stos g_colors[] =
{
	{"{bol}", ON_BOLD},
	{"{und}", ON_UNDERLINED},
	{"{inv}", ON_INVERTED},
	{"{bla}", FG_BLACK},
	{"{red}", FG_RED},
	{"{gre}", FG_GREEN},
	{"{yel}", FG_YELLOW},
	{"{blu}", FG_BLUE},
	{"{mag}", FG_MAGENTA},
	{"{cya}", FG_CYAN},
	{"{eoc}", FG_DEFAULT},
	{NULL, NULL},
};

void	ft_printf_color(int fd, char **final, char **str)
{
	int		i;

	i = 0;
	while (g_colors[i].key)
	{
		if (ft_strncmp(*str, g_colors[i].key, 5) == 0)
		{
			(void)fd;
			*final = ft_strjoin(*final, g_colors[i].val);
			*str += 5;
			return ;
		}
		i++;
	}
}
