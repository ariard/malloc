/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 19:53:56 by ariard            #+#    #+#             */
/*   Updated: 2017/03/10 20:17:50 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <unistd.h>
# include "types.h"

struct	s_config
{
	int		page_size;
	int		tiny_area;
	int		small_area;
	int		limit_tiny;
	int		limit_small;
};

struct	s_chunk
{
	s_chunk		*next;
	s_chunk		*previous;
	int		status;
	int		size;
	char		data[1];
}

struct	s_bin
{
	s_bin		*next;
	s_chunk		*first;
	int		size;
	int		free;
}
	
extern	s_bin		first_bin;

#endif

void		malloc_init(t_config *config);

