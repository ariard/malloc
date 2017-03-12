/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 19:53:56 by ariard            #+#    #+#             */
/*   Updated: 2017/03/12 16:45:17 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <unistd.h>
# include <sys/mman.h>
# include "types.h"
# include "../libft/includes/libft.h"

# define YELLOW	"\x1b[33m"
# define GREEN	"\x1b[32m"		
# define RED	"\x1b[31m"
# define RESET	"\x1b[0m"


# define DBG(s, ...)	dprintf(3, s, ##__VA_ARGS__);	

struct	s_config
{
	int		page_size;
	int		tiny_area;
	int		small_area;
	size_t	limit_tiny;
	size_t	limit_small;
};

enum	e_status
{
	EMPTY,
	FULL,
	FREED,
};

struct	s_chunk
{
	struct	s_chunk		*next;
	struct 	s_chunk		*previous;
	int					status;
	int					size;
	char				data[1];
};

struct	s_bin
{
	struct	s_bin		*next;
	struct s_chunk		*first;
	size_t				size;
	t_status			status;
	char				data[1];
};
	
extern	struct s_bin	*first_bin;

void		malloc_init(t_config *config);
void		bin_init(t_bin *bin, size_t size);
t_bin		*bin_add(t_config *config, size_t size);
int			bin_check(t_bin *temp, size_t size);
void		*bin_pack(t_bin *bin, size_t size);

#endif
