/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 19:53:56 by ariard            #+#    #+#             */
/*   Updated: 2018/01/06 23:34:03 by ariard           ###   ########.fr       */
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


# define TINY(x)		(x + 16) + (16 - (x + 16) % 16)
# define SMALL(x)		(x + 16) + (512 - (x + 16) % 512)

struct	s_config
{
	int	page_size;
	int	tiny_area;
	int	small_area;
	size_t	limit_tiny;
	size_t	limit_small;
};

enum	e_status
{
	EMPTY,
	FULL,
	FREED,
};

//struct	s_chunk
//{
//	struct	s_chunk		*next;
//	struct 	s_chunk		*previous;
//	int			status;
//	size_t			size;
//	char			data[1];
//};

//struct	s_bin
//{
//	struct s_bin		*next;
//	struct s_chunk		*first_chunk;
//	size_t			size;
//	size_t			freespace;
//	char			data[1];
//};
//
struct	s_bin
{
	struct s_bin		*next;
	void				*first;
	size_t				freespace;
};

struct s_chunk
{
	struct s_chunk		*next;
	struct s_chunk		*prev;
};

extern	struct s_bin	*first_bin;

void		malloc_init(t_config *config);
t_bin		*bin_add(t_config *config, size_t request);
void		*bin_pack(t_config *config, t_bin *bin, size_t request);
void		*chunk_init(t_config *config, t_bin *bin, t_chunk *chunk, size_t request);

/* Debug */

void		read_freelist(void);

#endif
