/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 19:53:56 by ariard            #+#    #+#             */
/*   Updated: 2018/01/24 21:41:03 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <unistd.h>
# include <sys/mman.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft/includes/libft.h"
# include "types.h"

# define GREEN			"\x1b[32m"
# define RESET			"\x1b[0m"
# define RED			"\x1b[31m"

# define DBG(s, ...)	level(3, s, ##__VA_ARGS__);

# define BT(x)		*(size_t *)((void *)x - sizeof(size_t))
# define LT(x, s) 	*(size_t *)(x + s - 2 * sizeof(size_t) - 2 * sizeof(char))

# define SUM(x)		*(char *)((void *)x - sizeof(size_t) - sizeof(char))
# define LSUM(x, s)	*(char *)(x + s - 2 * sizeof(size_t) - sizeof(char))


# define LT_PREV(x)	*(size_t *)(x - 2 * sizeof(size_t) - 2 * sizeof(char))

# define FREE(x)		x & 0
# define SET_BUSY(x)	x | (1 << 0)
# define SET_FREE(x)	x & ~(1 << 0)

# define NEXT(x)		(*(size_t *)(void *)x - sizeof(size_t) & ~(1 << 0))
# define PREV(x)		(*(size_t *)(void *)x - sizeof(size_t) & ~(1 << 0))

struct		s_bin
{
	struct s_bin		*next;
	void				*first;
	size_t				freespace;
};

struct		s_area
{
	t_bin				*list[3];
	pthread_mutex_t		mutex;
	char				reentrancy;
};

struct		s_config
{
	int					page_size;
	size_t				tiny_area;
	size_t				small_area;
	size_t				limit_tiny;
	size_t				limit_small;
	t_area				areas[4];
	pthread_key_t		key;
	pthread_once_t		once;
};

enum		e_status
{
	EMPTY,
	FULL,
	FREED,
};

struct		s_bins
{
	t_bin				*bin;
	t_bin				*prev;
	char				a;
};

struct		s_chunk
{
	struct s_chunk		*next;
	struct s_chunk		*prev;
};

struct		s_cand
{
	void				*chunk;
	size_t				size;
	size_t				backward;
	size_t				forward;
};

struct		s_ctrl
{
	size_t				sum;
	char				pos;
};

extern t_config			g_cfg;

void		malloc_init(void);

t_bin		*bin_add(size_t request);
void		*bin_pack(t_area *area, t_bin *bin, size_t request);
int			bin_checkin(t_bin *bin, void *ptr, char area, char pos);

t_bins		chunk_find(t_area *ar, void *ptr);
void		*chunk_init(t_bin *bin, t_chunk *chunk, size_t request);
void		*chunk_coalesce(t_area *area, t_chunk *list, size_t request, char range);
int			chunk_search(t_bins bs, void *chunk, size_t request, t_ctrl ctrl);
t_bins		chunk_find(t_area *area, void *ptr);
void		*chunk_merge(void *ptr, size_t forward, size_t backward);
void		*chunk_error(void);
char		chunk_check(void *ptr);

t_area		*thread_set(void);
void		thread_unset2(t_area *area);

int			align(int x, int f);

void		area_print(t_bin *bin, int a);
void		show_alloc_mem(void);
void		show_free_mem(void);
void		show_cand_merge(void *ptr, t_cand cand);
void		level(int fd, char *s, ...);

#endif
